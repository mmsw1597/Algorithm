#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int s[100000];
int e[100000];

struct meeting {
    int begin, end;
};

bool cmp(meeting& u, meeting& v) {
    if (u.end == v.end) {
        return u.begin < v.begin;
    }
    else {
        return u.end < v.end;
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    int x, y;
    cin >> n;
    vector<meeting> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].begin >> v[i].end;
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 1;
    int end = v[0].end;

    for (int i = 1; i < v.size(); i++) {
        if (v[i].begin < end)
            continue;

        end = v[i].end;
        ans++;

    }
    cout << ans << '\n';


    return 0;
}