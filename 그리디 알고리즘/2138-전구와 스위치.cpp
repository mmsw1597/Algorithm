#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

char b[100000];
int n, m;

void swap(int x, vector<char>& a) {
    if (x == n - 1) {
        for (int i = x - 1; i <= x; i++) {
            if (a[i] == '1')
                a[i] = '0';
            else
                a[i] = '1';
        }
        return;
    }

    for (int i = x - 1; i <= x + 1; i++) {
        if (a[i] == '1')
            a[i] = '0';
        else
            a[i] = '1';
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    vector<char> a(n);
    vector<char> a2(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a2 = a;

    for (int i = 0; i < 2; i++) {
        if (a2[i] == '1')
            a2[i] = '0';
        else
            a2[i] = '1';
    }

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans1 = 0;
    int ans2 = 1;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] != b[i - 1]) {
            swap(i, a);
            ans1++;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a2[i - 1] != b[i - 1]) {
            swap(i, a2);
            ans2++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            ans1 = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a2[i] != b[i]) {
            ans2 = -1;
        }
    }

    if (ans1 == -1 && ans2 == -1)
        cout << -1 << '\n';
    else if (ans1 != -1)
        cout << ans1 << '\n';
    else if (ans2 != -1)
        cout << ans2 << '\n';
    else
        cout << (ans1 < ans2) ? ans1 : ans2 << '\n';

    return 0;
}