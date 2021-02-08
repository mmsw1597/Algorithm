#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

bool check[20 * 100000 + 1];
int a[20];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        check[sum] = true;
    }

    for (int i = 1;; i++) {
        if (check[i] == false) {
            cout << i << '\n';
            break;
        }
    }


    return 0;
}