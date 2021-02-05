#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[20];
bool ans[2000001];
int n, s;

void go(int idx, int sum) {
    if (idx >= n && sum != 0) {
        ans[sum] = true;
        return;
    }
    else if (idx >= n && sum == 0)
        return;

    go(idx + 1, sum + a[idx]);
    go(idx + 1, sum);
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    go(0, 0);
    for (int i = 1; i <= 2000000; i++) {
        if (ans[i] == false) {
            cout << i << '\n';
            break;
        }

    }

    return 0;
}