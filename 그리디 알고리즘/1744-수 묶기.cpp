#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n;

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    cin >> n;

    vector<int> a;
    vector<int> b;


    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num > 0)
            a.push_back(num);
        else
            b.push_back(num);
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end());

    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i + 1 != a.size() && a[i] != 1 && a[i + 1] != 1) {
            sum += a[i] * a[i + 1];
            i += 1;
        }
        else if (i + 1 != a.size() && (a[i] == 1 || a[i + 1] == 1)) {
            sum += a[i];
        }
        else if (i + 1 == a.size())
            sum += a[i];
    }

    for (int i = 0; i < b.size(); i++) {
        if (i + 1 != b.size() && b[i] != 0 && b[i + 1] != 0) {
            sum += b[i] * b[i + 1];
            i += 1;
        }

        else if (i + 1 != b.size() && (b[i] == 0 || b[i + 1] == 0)) {
            i += 1;
        }

        else if (i + 1 == b.size())
            sum += b[i];
    }

    cout << sum << '\n';

    return 0;
}