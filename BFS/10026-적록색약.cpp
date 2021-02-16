#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int n;
char a[100][100];
bool check_1[100][100];
bool check_2[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs1(int x, int y, char col) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check_1[x][y] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (a[nx][ny] == col && check_1[nx][ny] == false) {
                    q.push(make_pair(nx, ny));
                    check_1[nx][ny] = true;
                }
            }
        }
    }
    return;
}

void bfs2(int x, int y, char col) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check_2[x][y] = true;

    bool btn = false;

    if (col == 'R' || col == 'G')
        btn = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (btn) {
                    if ((a[nx][ny] == 'R' || a[nx][ny] == 'G') && check_2[nx][ny] == false) {
                        q.push(make_pair(nx, ny));
                        check_2[nx][ny] = true;
                    }
                }
                else {
                    if (a[nx][ny] == col && check_2[nx][ny] == false) {
                        q.push(make_pair(nx, ny));
                        check_2[nx][ny] = true;
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

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check_1[i][j] == false) {
                bfs1(i, j, a[i][j]);
                cnt1++;
            }

            if (check_2[i][j] == false) {
                bfs2(i, j, a[i][j]);
                cnt2++;
            }
        }
    }

    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}