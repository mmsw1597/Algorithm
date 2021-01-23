#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int a[8][8];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };

void bfs(int x, int y) {
    queue<pair <int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        pair<int, int> node = q.front();
        int nx = node.first;
        int ny = node.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (nx + dx[i] >= 0 && nx + dx[i] < n && ny + dy[i] >= 0 && ny + dy[i] < m) {
                if (a[nx + dx[i]][ny + dy[i]] == 0) {
                    pair<int, int > next = make_pair(nx + dx[i], ny + dy[i]);

                    a[next.first][next.second] = 3;
                    q.push(next);

                }
            }       
        }
    }
}

void go(int h, int w, int cnt, int &max) {
    if (cnt == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2)
                    bfs(i, j);
            }
        }

        int num = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0)
                    num++;
                if (a[i][j] == 3)
                    a[i][j] = 0;
            }
        }

        if (max < num)
            max = num;

        cnt -= 1;
        a[h][w] = 0;
        return;
    }



    for (int i = h; i < n; i++) {
        for (int j = w; j < m; j++) {
            if (a[i][j] == 0) {
                a[i][j] = 1;
                go(i, j, cnt + 1, max);
                a[i][j] = 0;
            }
            if (j == m - 1)
                w = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n>>m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
   
    int max = 0;
    go(0, 0, 0, max);
    cout << max << '\n';
    return 0;
}
