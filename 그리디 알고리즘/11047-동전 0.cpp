#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <string>
#include <tuple>

using namespace std;

int arr[10];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = n - 1;
    int temp = k;
    int ans = 0;

    while (idx >= 0) {
        if (temp < arr[idx]) {
            idx--;
        }

        else {
            ans += (temp / arr[idx]);
            temp %= arr[idx];

        }
    }

    cout << ans << '\n';

    return 0;
}