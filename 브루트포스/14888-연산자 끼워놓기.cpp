#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[20];
int op[4];

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < op[i]; j++) {
            b.push_back(i);
        }
    }

    long long int max = -1000000001;
    long long int min = 1000000001;

    do {
        long long int sum = a[0];

        for (int i = 1; i < n; i++) {

            if (b[i - 1] == 0) {
                sum = (sum + a[i]);
            }
            else if (b[i - 1] == 1) {
                sum = (sum - a[i]);
            }
            else if (b[i - 1] == 2) {
                sum = (sum * a[i]);
            }
            else if (b[i - 1] == 3) {
                sum = (sum / a[i]);
            }

        }

        if (sum > max)
            max = sum;
        if (sum < min)
            min = sum;
    } while (next_permutation(b.begin(), b.end()));

    cout << max << '\n';
    cout << min << '\n';

    return 0;
}