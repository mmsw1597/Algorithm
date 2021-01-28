#include <iostream>

using namespace std;

long long int dp[1001][10];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    long long int mod = 10007;

    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = j; k <= 9; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }

    long long int ans = 0;

    for (int i = 0; i < 10; i++)
        ans += dp[n][i];
    ans %= mod;

    cout << ans << '\n';

    return 0;
}