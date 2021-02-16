#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int w, h;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
char a[100][100];
bool check[100][100];
int b[100][100];

void bfs(pair<int, int> c1, pair<int, int> c2) {
    queue<pair<int, int>> q;
    q.push(make_pair(c1.first, c1.second));
    check[c1.first][c1.second] = true;

    while (!q.empty()) {
        int x, y, z;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while (nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] != '*') {
                if (check[nx][ny] == false) {
                    b[nx][ny] = b[x][y] + 1;
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
        if (check[c2.first][c2.second]) {
            cout << b[c2.first][c2.second] - 1 << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> w >> h;

    vector<pair<int, int>> c;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'C')
                c.push_back(make_pair(i, j));
        }
    }


    bfs(c[0], c[1]);


    return 0;
}