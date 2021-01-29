#include <iostream>
#include <vector>

using namespace std;

int A[1001];
int dp[1001];
int v[1001];

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    int temp = (a > b) ? a : b;

    return (temp > c) ? temp : c;
}

void go(int p) {
    if (p == 0)
        return;

    go(v[p]);
    cout << A[p] << ' ';
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    dp[1] = 1;
    int ans = 1;
    int idx = 0;
    int max = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 1;
        idx = 0;

        for (int j = i - 1; j > 0; j--) {
            if (A[j] < A[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
                idx = j;
            }
        }

        v[i] = idx;
        if (ans < dp[i]) {
            ans = dp[i];
            max = i;
        }
    }

    cout << ans << '\n';
    go(v[max]);
    cout << A[max] << '\n';

    return 0;
}