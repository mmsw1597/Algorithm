#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
char a[1001][1001];
int b[1001][1001][11];
bool check[1001][1001][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));
    check[0][0][0] = true;
    b[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (a[nx][ny] == '0') {
                    if (check[nx][ny][z] == false) {
                        b[nx][ny][z] = b[x][y][z] + 1;
                        check[nx][ny][z] = true;
                        q.push(make_tuple(nx, ny, z));
                    }
                }
                if (a[nx][ny] == '1') {
                    if (check[nx][ny][z + 1] == false && z < k) {
                        b[nx][ny][z + 1] = b[x][y][z] + 1;
                        check[nx][ny][z + 1] = true;
                        q.push(make_tuple(nx, ny, z + 1));
                    }
                }
            }
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1;

    bfs();

    for (int i = 0; i <= k; i++) {
        if (b[n - 1][m - 1][i] != 0) {
            if (ans > b[n - 1][m - 1][i] || ans == -1)
                ans = b[n - 1][m - 1][i];
        }
    }

    cout << ans << '\n';

    return 0;
}