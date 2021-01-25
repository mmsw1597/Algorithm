#include <iostream>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

char a[1001][1001];
bool check[1001][1001][2];
int d[1001][1001][2];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0, };

void bfs() {
    queue<tuple <int, int,int>> q;
    q.push(make_tuple(1,1,0));
   
    check[1][1][0] = true;
    d[1][1][0] = 1;

    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
       
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m) {
                if (a[x + dx[i]][y + dy[i]] == '0') {
                    if (z == 0 && check[nx][ny][0] == false) {
                        tuple<int, int, int > next = make_tuple(nx , ny, z);
                        q.push(next);
                        d[nx][ny][0] = d[x][y][0] + 1;
                        check[nx][ny][0] = true;
                    }
                    
                    else if (z == 1 && check[nx][ny][1] == false) {
                        tuple<int, int, int > next = make_tuple(nx, ny, z);
                        q.push(next);
                        d[nx][ny][1] = d[x][y][1] + 1;
                        check[nx][ny][1] = true;
                    }
                    
                }
                if (a[nx][ny] == '1') {
                    if (z == 0 && check[nx][ny][1] == false) {
                        tuple<int, int, int > next = make_tuple(nx, ny, 1);
                        q.push(next);
                        d[nx][ny][1] = d[x][y][0] + 1;
                        check[nx][ny][1] = true;
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

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    bfs();

    int a = (d[n][m][0] == 0 ? -1 : d[n][m][0]);
    int b = (d[n][m][1] == 0 ? -1 : d[n][m][1]);
    int ans;

    if (a == -1 && b == -1)
        ans = -1;
    else if (a == -1)
        ans = b;
    else if (b == -1)
        ans = a;
    else
        ans = a > b ? b : a;

    cout << ans << '\n';
    return 0;
}