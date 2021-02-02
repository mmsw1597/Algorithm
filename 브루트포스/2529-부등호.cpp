#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char s[10];
bool m = false;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    int max[10];
    int min[10];

    vector<int> a(n + 1);
    int num = 0;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int k = 0; k < 10 - n; k++) {
        for (int i = 0; i < n + 1; i++) {
            a[i] = num++;
        }

        num = k + 1;

        do {
            bool btn = true;

            for (int i = 0; i < n; i++) {
                if (a[i] > a[i + 1] && s[i] == '<') {
                    btn = false;
                    break;
                }

                if (a[i] < a[i + 1] && s[i] == '>') {
                    btn = false;
                    break;
                }
            }

            if (btn) {
                if (!m) {
                    for (int i = 0; i < n + 1; i++)
                        min[i] = a[i];
                    m = true;
                }

                for (int i = 0; i < n + 1; i++)
                    max[i] = a[i];
            }
        } while (next_permutation(a.begin(), a.end()));
    }

    for (int i = 0; i < n + 1; i++)
        cout << max[i];
    cout << '\n';

    for (int i = 0; i < n + 1; i++)
        cout << min[i];
    cout << '\n';

    return 0;
}