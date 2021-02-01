#include <iostream>
#include <vector>

using namespace std;

long long int dp[201][201];

int max2(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    int temp = (a > b) ? a : b;

    return (temp > c) ? temp : c;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int e = 0; e <= i; e++) {
                if (j == 1)
                    dp[i][j] = 1;
                else {
                    dp[i][j] += dp[i - e][j - 1] * dp[e][1];
                }
                dp[i][j] %= 1000000000;
            }
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}