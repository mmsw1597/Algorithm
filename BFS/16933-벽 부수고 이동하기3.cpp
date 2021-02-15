#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;
bool day = true;
char a[1000][1000];
int b[1000][1000][11][2];
bool check[1000][1000][11];
bool rest[1000][1000][11];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    queue<tuple<int, int, pair<int, int>>> q;
    q.push(make_tuple(0, 0, make_pair(0, 0)));
    check[0][0][0] = true;
    b[0][0][0][0] = 1;

    while (!q.empty()) {
        int s = q.size();

        for (int j = 0; j < s; j++) {
            int x, y;
            pair<int, int> p;

            tie(x, y, p) = q.front();
            int z = p.first;
            int r = p.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (day == true) {
                        if (a[nx][ny] == '0') {
                            if (check[nx][ny][z] == false) {
                                q.push(make_tuple(nx, ny, make_pair(z, 0)));
                                check[nx][ny][z] = true;
                                b[nx][ny][z][0] = b[x][y][z][r] + 1;
                            }
                        }
                        else if (a[nx][ny] == '1') {
                            if (check[nx][ny][z + 1] == false && z < k) {
                                q.push(make_tuple(nx, ny, make_pair(z + 1, 0)));
                                check[nx][ny][z + 1] = true;
                                b[nx][ny][z + 1][0] = b[x][y][z][r] + 1;
                            }
                        }
                    }

                    else {
                        if (a[nx][ny] == '0') {
                            if (check[nx][ny][z] == false) {
                                q.push(make_tuple(nx, ny, make_pair(z, 0)));
                                check[nx][ny][z] = true;
                                b[nx][ny][z][0] = b[x][y][z][r] + 1;
                            }
                        }

                        if (rest[x][y][z] == false) {
                            q.push(make_tuple(x, y, make_pair(z, 1)));
                            rest[x][y][z] = true;
                            b[x][y][z][1] = b[x][y][z][0] + 1;
                        }

                    }
                }
            }
        }

        day = !day;
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    bfs();
    int ans = -1;

    for (int i = 0; i <= k; i++) {
        if (check[n - 1][m - 1][i]) {
            if (ans == -1 || ans > b[n - 1][m - 1][i][0])
                ans = b[n - 1][m - 1][i][0];
        }
    }

    cout << ans << '\n';

    return 0;
}