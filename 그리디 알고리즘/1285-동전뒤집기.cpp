#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n;
int ans = -1;
bool check[20];

char swap(char cur) {
    if (cur == 'T')
        return 'H';
    else
        return 'T';
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    vector<vector<char>> a(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            a[i].push_back(ch);
        }
    }

    for (int state = 0; state < (1 << n); state++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                char cur = a[i][j];
                if (state & (1 << i)) {
                    cur = swap(cur);
                }
                if (cur == 'T') {
                    cnt += 1;
                }
            }

            sum += (cnt > n - cnt ? n - cnt : cnt);
        }
        if (ans == -1 || ans > sum)
            ans = sum;
    }

    cout << ans << '\n';

    return 0;
}