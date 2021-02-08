#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool check[50][15];

int count(int mask, vector<int> v) {
    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        if ((v[i] & ((1 << 26) - 1 - mask)) == 0) {
            cnt += 1;
        }
    }

    return cnt;
}

int go(int index, int k, int mask, vector<int>& v) {
    if (k < 0)
        return 0;

    if (index == 26)
        return count(mask, v);

    int ans = 0;
    int t1 = go(index + 1, k - 1, mask | (1 << index), v);
    if (ans < t1) ans = t1;

    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a'
        && index != 'c' - 'a') {
        t1 = go(index + 1, k, mask, v);
        if (ans < t1) ans = t1;
    }
    return ans;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, k;

    cin >> n >> k;
    vector<int> v(n);
    char str[50][15];

    for (int i = 0; i < n; i++) {
        cin >> str[i];
        int idx = 0;
        while (str[i][idx] != '\0') {
            v[i] |= (1 << (str[i][idx++] - 'a'));
        }
    }

    int ans = go(0, k, 0, v);
    cout << ans << '\n';
    return 0;
}