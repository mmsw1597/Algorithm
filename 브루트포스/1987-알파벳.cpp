#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

char a[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool check[26];
int r, c;

void go(int x, int y, int cnt, int& max) {
    if (max < cnt)
        max = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < r && nx >= 0 && ny < c && ny >= 0) {
            if (check[a[nx][ny] - 'A'] == false) {
                check[a[nx][ny] - 'A'] = true;
                go(nx, ny, cnt + 1, max);
                check[a[nx][ny] - 'A'] = false;
            }
        }
    }
    return;
}


int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    int max = 0;

    check[a[0][0] - 'A'] = true;
    go(0, 0, 1, max);

    cout << max << '\n';

    return 0;
}