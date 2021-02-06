#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

char a[22][22];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

void go(pair<int, int> p1, pair<int, int> p2, int cnt, int& min) {
    if (cnt > 10)
        return;

    int x1 = p1.first;
    int y1 = p1.second;

    int x2 = p2.first;
    int y2 = p2.second;

    if ((x1 > n || x1 < 1 || y1 > m || y1 < 1) && (x2 > n || x2 < 1 || y2 > m || y2 < 1)) {
        return;
    }
    else if ((x1 > n || x1 < 1 || y1 > m || y1 < 1)) {
        if (min > cnt || min == -1)
            min = cnt;
        return;
    }
    else if ((x2 > n || x2 < 1 || y2 > m || y2 < 1)) {
        if (min > cnt || min == -1)
            min = cnt;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int dx1 = x1 + dx[i];
        int dy1 = y1 + dy[i];

        int dx2 = x2 + dx[i];
        int dy2 = y2 + dy[i];

        if (a[dx1][dy1] == '#' && a[dx2][dy2] == '#')
            continue;
        else if (a[dx1][dy1] == '#')
            go(make_pair(x1, y1), make_pair(dx2, dy2), cnt + 1, min);
        else if (a[dx2][dy2] == '#')
            go(make_pair(dx1, dy1), make_pair(x2, y2), cnt + 1, min);
        else
            go(make_pair(dx1, dy1), make_pair(dx2, dy2), cnt + 1, min);
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    pair<int, int> p1;
    pair<int, int> p2;
    bool btn = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o' && btn == false) {
                p1 = make_pair(i, j);
                btn = true;
            }
            if (a[i][j] == 'o' && btn == true) {
                p2 = make_pair(i, j);
            }
        }
    }
    int min = -1;
    go(p1, p2, 0, min);

    cout << min << '\n';

    return 0;
}