#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1, 0 ,-1 };
int n, m;

vector<int> gen(int k) {
    vector<int> v(5);

    for (int i = 0; i < 5; i++) {
        v[i] = (k & 3);
        k >>= 2;
    }

    return v;
}

int move(vector<vector<int>>& a, int dir) {
    int x = 0;
    int y = 0;
    int max = 0;
    bool ch[20][20] = { false, };

    int sdir = dir + 1;


    if (dir == 3)
        sdir = 2;
    else if (dir == 2)
        sdir = 1;

    if (dir == 0) {
        x = 1, y = 0;
    }
    else if (dir == 1) {
        x = 0, y = n - 2;
    }
    else if (dir == 2) {
        x = n - 2, y = 0;
    }
    else if (dir == 3) {
        x = 0, y = 1;
    }

    for (int i = 1; i < n; i++) {
        int qx = x;
        int qy = y;

        for (int j = 0; j < n; j++) {
            int nx = qx;
            int ny = qy;

            if (a[nx][ny] != 0 && a[nx + dx[dir]][ny + dy[dir]] == 0) {
                while (a[nx + dx[dir]][ny + dy[dir]] == 0) {
                    swap(a[nx][ny], a[nx + dx[dir]][ny + dy[dir]]);
                    nx += dx[dir];
                    ny += dy[dir];

                    if (nx + dx[dir] == n || nx + dx[dir] < 0 || ny + dy[dir] == n || ny + dy[dir] < 0)
                        break;
                }
            }

            if (nx + dx[dir] == n || nx + dx[dir] < 0 || ny + dy[dir] == n || ny + dy[dir] < 0) {
                qx += dx[sdir];
                qy += dy[sdir];
                continue;
            }

            if (a[nx][ny] != 0 && a[nx][ny] == a[nx + dx[dir]][ny + dy[dir]] && ch[nx + dx[dir]][ny + dy[dir]] == false) {
                a[nx + dx[dir]][ny + dy[dir]] += a[nx][ny];
                ch[nx + dx[dir]][ny + dy[dir]] = true;
                if (max < a[nx + dx[dir]][ny + dy[dir]])
                    max = a[nx + dx[dir]][ny + dy[dir]];
                a[nx][ny] = 0;
            }

            qx += dx[sdir];
            qy += dy[sdir];
        }
        x -= dx[dir];
        y -= dy[dir];
    }

    return max;
}

int check(vector<vector<int>> a, vector<int> v) {
    int max = 0;
    bool ch[20][20];

    for (int i = 0; i < v.size(); i++) {
        int cur = move(a, v[i]);
        if (cur == 0)
            continue;
        if (max < cur)
            max = cur;
    }

    return max;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;

    vector<vector<int>> a(n);
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (max < num)
                max = num;
            a[i].push_back(num);
        }
    }

    if (n == 1) {
        cout << max << '\n';
        return 0;
    }

    for (int i = 0; i < (1 << 10); i++) {
        vector<int> v = gen(i);

        int cur = check(a, v);
        if (max < cur)
            max = cur;
    }

    cout << max << '\n';
    return 0;
}