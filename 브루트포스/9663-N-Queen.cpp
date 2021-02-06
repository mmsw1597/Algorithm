#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool check_1[40];
bool check_2[40];
bool check_3[40];
bool a[15][15];
int n, m;
int ans = 0;

bool go(int x, int y) {
    if (check_1[y])
        return false;

    if (check_2[x + y])
        return false;

    if (check_3[x - y + n])
        return false;

    return true;
}

void calc(int row) {
    if (row == n) {
        ans += 1;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (go(row, col)) {
            a[row][col] = true;
            check_1[col] = true;
            check_2[row + col] = true;
            check_3[row - col + n] = true;
            calc(row + 1);
            a[row][col] = false;
            check_1[col] = false;
            check_2[row + col] = false;
            check_3[row - col + n] = false;
        }
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;

    calc(0);

    cout << ans << '\n';

    return 0;
}