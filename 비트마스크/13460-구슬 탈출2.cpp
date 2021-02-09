#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1, 0 ,-1 };
int n, m;

vector<int> gen(int k) {
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = (k & 3);
        k >>= 2;
    }
    return v;
}

bool valid(vector<int>& v) {
    int l = v.size();
    for (int i = 0; i + 1 < l; i++) {
        if (v[i] == v[i + 1]) return false;
        if (v[i] == 3 && v[i + 1] == 1) return false;
        if (v[i] == 2 && v[i + 1] == 0) return false;
        if (v[i] == 1 && v[i + 1] == 3) return false;
        if (v[i] == 0 && v[i + 1] == 2) return false;
    }
    return true;
}

pair<bool, bool> simulation(vector<string>& a, int d, int& x, int& y) {
    bool moved = false;
    if (a[x][y] == '.') return make_pair(false, false);
    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (a[nx][ny] == '#')
            return make_pair(moved, false);

        else if (a[nx][ny] == 'R' || a[nx][ny] == 'B')
            return make_pair(moved, false);

        else if (a[nx][ny] == '.') {
            moved = true;
            swap(a[x][y], a[nx][ny]);
            x = nx;
            y = ny;
        }
        else if (a[nx][ny] == 'O') {
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
}

int go(vector<string> a, vector<int>& v, pair<int, int> r, pair<int, int> b) {
    int rx = r.first;
    int ry = r.second;

    int bx = b.first;
    int by = b.second;

    int ans = 0;

    for (int k : v) {
        ans += 1;
        bool hole1 = false, hole2 = false;
        pair<bool, bool> p1 = make_pair(true, hole1);
        pair<bool, bool> p2 = make_pair(true, hole2);
        while (true) {
            p1 = simulation(a, k, rx, ry);
            p2 = simulation(a, k, bx, by);

            if (p1.first == false && p2.first == false)
                break;

            if (p1.second)
                hole1 = true;
            if (p2.second)
                hole2 = true;
        }
        if (hole2) return -1;
        if (hole1) return ans;

    }

    return -1;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;

    pair<int, int> r;
    pair<int, int> b;
    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int idx = 0;
        for (char x : a[i]) {
            if (x == 'R')
                r = make_pair(i, idx);
            if (x == 'B')
                b = make_pair(i, idx);
            idx++;
        }
    }

    int ans = -1;

    for (int k = 0; k < (1 << 20); k++) {
        vector<int> v = gen(k);

        if (!valid(v)) continue;

        int temp = go(a, v, r, b);
        if (temp == -1)
            continue;

        if (ans == -1 || ans > temp)
            ans = temp;
    }

    cout << ans << '\n';
    return 0;
}