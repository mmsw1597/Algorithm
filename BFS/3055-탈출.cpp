#include <iostream>
#include <deque>
#include <queue>
#include <utility>

using namespace std;

char a[51][51];
bool check[51][51];
int d[51][51];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };

void bfs(pair <int,int> start , pair<int,int> end) {
    queue<pair <int, int>> r;
    queue<pair<int, int>> w;
    r.push(start);
    check[start.first][start.second] = true;
    d[start.first][start.second] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '*') {
                w.push(make_pair(i, j));
                check[i][j] = true;
            }
        }
    }
    
    while (!r.empty() || !w.empty()) {
        if (d[end.first][end.second] != 0)
            return;

        int size_w = w.size();
        int size_r = r.size();

        for (int i = 0; i < size_w; i++) {
        int x, y;
        x = w.front().first;
        y = w.front().second;
        w.pop();
        
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
                    if (a[nx][ny] == '.' && check[nx][ny] == false) {
                        pair<int, int > next = make_pair(nx, ny);
                        w.push(next);
                        check[nx][ny] = true;
                        a[nx][ny] = '*';
                    }
                }
            }
        }

        for (int i = 0; i < size_r; i++) {
            int x, y;
            x = r.front().first;
            y = r.front().second;
            r.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
                    if ((a[nx][ny] == '.' || a[nx][ny] =='D') && check[nx][ny] == false) {
                        pair<int, int > next = make_pair(nx, ny);
                        r.push(next);
                        check[nx][ny] = true;
                        d[nx][ny] = d[x][y] + 1;
                    }
                }
            }
        }

    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    pair <int, int> start;
    pair <int, int> end;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'S')
                start = make_pair(i, j);
            if (ch == 'D')
                end = make_pair(i, j);
            a[i][j] = ch;
        }
    }

    bfs(start,end);

    if (d[end.first][end.second] == 0) {
        cout << "KAKTUS" << '\n';
    }
    else
        cout << d[end.first][end.second] << '\n';

    return 0;
}