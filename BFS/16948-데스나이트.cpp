#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool check[200][200];
int dist[200][200];
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

void bfs(pair<int, int> s, pair<int, int> e) {
    queue<pair<int, int>> q;
    q.push(s);
    check[s.first][s.second] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            if (x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0) {
                if (check[x + dx[i]][y + dy[i]] == false) {
                    q.push(make_pair(x + dx[i], y + dy[i]));
                    check[x + dx[i]][y + dy[i]] = true;
                    dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
                }
            }
        }

        if (check[e.first][e.second] == true)
            return;
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int x1, y1, x2, y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<int, int> start = make_pair(x1, y1);
    pair<int, int> end = make_pair(x2, y2);

    dist[end.first][end.second] = -1;
    bfs(start, end);

    cout << dist[end.first][end.second] << '\n';

    return 0;
}