#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;


struct jwel {
    int m;
    int v;
};

int n, k;

bool cmp(jwel x, jwel y) {
    return x.v > y.v;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> k;
    int limit = -1;

    multiset<int> m;
    vector<jwel> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].m >> v[i].v;
    }

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        m.insert(a);
    }

    long long sum = 0;
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        if (m.lower_bound(v[i].m) != m.end()) {
            m.erase(m.lower_bound(v[i].m));
            sum += v[i].v;
        }
    }

    cout << sum << '\n';

    return 0;
}