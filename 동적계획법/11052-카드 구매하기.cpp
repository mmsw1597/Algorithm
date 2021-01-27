#include <iostream>

using namespace std;

int dp[1001];
int p[1001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
   
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    dp[1] = p[1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int max = 0;
            max = dp[i - j] + p[j];
            if (dp[i] < max)
                dp[i] = max;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}