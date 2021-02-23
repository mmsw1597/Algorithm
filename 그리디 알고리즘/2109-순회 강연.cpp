#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool check[10001];

struct lec {
    int d;
    int p;
};

int n, k;

bool cmp(lec x, lec y) {
    return x.p > y.p;
}

int max3(int a, int b, int c) {
    int temp = a > b ? a : b;

    return temp > c ? temp : c;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;

    vector<lec> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].p >> v[i].d;
    }

    sort(v.begin(), v.end(), cmp);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int day = v[i].d;

        while (day > 0 && check[day] == true) {
            day--;
        }
        if (day != 0) {
            sum += v[i].p;
            check[day] = true;
        }
    }

    cout << sum << '\n';

    return 0;
}