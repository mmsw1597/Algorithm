#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int n;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int a[20][20];
bool check[20][20];

pair<int, int> bfs(int r, int c, int s, int& t) {
    int check_1[20][20] = { 0, };

    queue < pair<int, int> >q;
    queue < pair<int, int> >ansq;
    q.push(make_pair(r, c));
    check_1[r][c] = 0;
    int temp = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (a[nx][ny] != 0 && a[nx][ny] < s && check_1[nx][ny] == 0) {
                    check_1[nx][ny] = check_1[x][y] + 1;


                    if (temp >= check_1[nx][ny] || temp == 0) {
                        ansq.push(make_pair(nx, ny));
                        temp = check_1[nx][ny];
                    }
                }

                if (a[nx][ny] <= s && check_1[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    check_1[nx][ny] = check_1[x][y] + 1;
                }
            }
        }
    }

    pair<int, int> ans = make_pair(n, n);
    bool btn = false;

    while (!ansq.empty()) {
        if (ans.first > ansq.front().first)
            ans = ansq.front();
        else if (ans.first == ansq.front().first) {
            if (ans.second > ansq.front().second)
                ans = ansq.front();
        }
        ansq.pop();
        btn = true;
    }
    if (btn)
        t += temp;

    return ans;
}

void go(int r, int c) {
    int s = 2;
    int e = 0;
    int t = 0;

    while (true) {
        pair<int, int> p = bfs(r, c, s, t);
        int x = p.first;
        int y = p.second;

        if (x == n && y == n)
            break;

        a[x][y] = 100;
        a[r][c] = 0;

        r = x;
        c = y;
        e += 1;
        if (e == s * (s + 1) / 2 - 1) {
            s += 1;
        }

    }

    cout << t << '\n';


}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    int x, y;
    int fish = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                x = i;
                y = j;
            }
            else if (a[i][j] != 0) {
                fish++;
            }
        }
    }

    a[x][y] = 100;
    go(x, y);

    return 0;
}