#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int dx[9] = { 0,0,0,1,-1,1,1,-1,-1 };
int dy[9] = { 0,1,-1,0,0,1,-1,-1,1 };
bool check[8][8][8];

void bfs(vector<string> a) {
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(7, 0, 0));
    check[7][0][0] = true;
    int cnt = 0;

    while (!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();

        for (int i = 0; i < 9; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = (t + 1 > 8 ? 8 : t + 1);

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (nx - t >= 0 && a[nx - t][ny] == '#')  continue;
                if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#') continue;
                if (check[nx][ny][nt] == false) {
                    q.push(make_tuple(nx, ny, nt));
                    check[nx][ny][nt] = true;

                    if (check[0][7][nt] == true) {
                        cout << 1 << '\n';
                        exit(0);
                    }
                }
            }
        }
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> a(8);

    for (int i = 0; i < 8; i++)
        cin >> a[i];

    bfs(a);
    cout << 0 << '\n';

    return 0;
}