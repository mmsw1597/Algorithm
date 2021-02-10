#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int a[1026][1026];
int dp[1026][1026];
int row[1026][1026];
int n, m;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    vector<pair<int, int>> s(m);
    vector<pair<int, int>> e(m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> s[i].first >> s[i].second;
        cin >> e[i].first >> e[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            row[i][j] = row[i][j - 1] + a[i][j];
            dp[i][j] += dp[i - 1][j] + row[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x1 = s[i].first;
        int y1 = s[i].second;
        int x2 = e[i].first;
        int y2 = e[i].second;

        int ans = dp[n][n] - dp[x1 - 1][n] - (dp[n][n] - dp[x2][n])
            - (dp[x2][y1 - 1] - dp[x1 - 1][y1 - 1]) - (dp[x2][n] - dp[x2][y2] - (dp[x1 - 1][n] - dp[x1 - 1][y2]));
        cout << ans << '\n';
    }

    return 0;
}