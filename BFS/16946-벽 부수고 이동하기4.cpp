#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char a[1001][1001];
int b[1001][1001];
int check[1001][1001];
int group[500 * 1000 + 1];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    int idx = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0' && check[i][j] == false) {
                queue<pair<int, int>> w;
                queue<pair<int, int>> q;
                int cnt = 1;
                q.push(make_pair(i, j));
                w.push(make_pair(i, j));
                check[i][j] = true;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (check[nx][ny] == false && a[nx][ny] == '0') {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                                w.push(make_pair(nx, ny));
                                cnt++;
                            }
                        }
                    }
                }
                while (!w.empty()) {
                    int x = w.front().first;
                    int y = w.front().second;
                    w.pop();
                    b[x][y] = idx;
                }
                group[idx++] = cnt;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                b[i][j] = 1;
                int arr[4];
                int num = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    bool btn = true;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (a[nx][ny] == '0') {
                            for (int e = 0; e < num; e++) {
                                if (arr[e] == b[nx][ny]) {
                                    btn = false;
                                    break;
                                }
                            }
                            if (btn) {
                                b[i][j] += group[b[nx][ny]];
                                arr[num++] = b[nx][ny];
                            }
                        }
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

    cin >> n >> m;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1')
                cout << (b[i][j]) % 10;
            else
                cout << '0';
        }
        cout << '\n';
    }

    return 0;
}