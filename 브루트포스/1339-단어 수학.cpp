#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int a[26];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(10);
    string s[10];
    long long int max = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i <= 9; i++)
        v[i] = i;

    long long int sum = 0;

    do {
        memset(a, -1, sizeof(a));
        sum = 0;
        int idx = 0;

        for (int i = 0; i < n; i++) {
            int size = s[i].size();
            long long int temp = 1;

            for (int j = 0; j < size - 1; j++)
                temp *= 10;

            for (int j = 0; j < size; j++) {
                for (int k = 0; k < 26; k++) {
                    if (s[i][j] == 'A' + k) {
                        if (a[k] == -1)
                            a[k] = v[idx++];

                        sum += a[k] * temp;
                        temp /= 10;
                        break;
                    }
                }
            }
        }
        if (max < sum)
            max = sum;
    } while (next_permutation(v.begin(), v.end()));

    cout << max << '\n';

    return 0;
}