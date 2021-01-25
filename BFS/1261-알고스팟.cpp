#include <iostream>
#include <deque>
#include <queue>
#include <utility>

using namespace std;

char a[101][101];
bool check[101][101];
int d[101][101];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };

void bfs(int x, int y) {
    deque<pair <int, int>> q;
    q.push_back(make_pair(x, y));

    while (!q.empty()) {
        pair<int, int> node = q.front();
        int nx = node.first;
        int ny = node.second;
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            if (nx + dx[i] >= 1 && nx + dx[i] <= n && ny + dy[i] >= 1 && ny + dy[i] <= m) {
                if (a[nx + dx[i]][ny + dy[i]] == '0' && check[nx + dx[i]][ny + dy[i]] == false) {
                    pair<int, int > next = make_pair(nx + dx[i], ny + dy[i]);
                    q.push_front(next);
                    check[nx + dx[i]][ny + dy[i]] = true;
                    d[nx + dx[i]][ny + dy[i]] = d[nx][ny];
                }
     
                else if (a[nx + dx[i]][ny + dy[i]] == '1' && check[nx + dx[i]][ny + dy[i]] == false) {
                    pair<int, int > next = make_pair(nx + dx[i], ny + dy[i]);
                    q.push_back(next);
                    check[nx + dx[i]][ny + dy[i]] = true;
                    d[nx + dx[i]][ny + dy[i]] = d[nx][ny] + 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    bfs(1, 1);
    cout << d[n][m] << '\n';
    return 0;
}
