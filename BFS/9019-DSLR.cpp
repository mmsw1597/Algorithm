#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, m;

string bfs(int s, int e) {
    queue<int> q;
    bool check[10000] = { false, };
    q.push(s);
    check[s] = true;

    string dist[10000];

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int d = (x * 2) % 10000;
        int s = (x == 0) ? 9999 : x - 1;
        int l = (x == 0) ? 0 : ((x % 1000) * 10 + (x / 1000));
        int temp = x / 10;
        int r = (x % 10) * 1000 + temp;

        if (check[d] == false) {
            q.push(d);
            check[d] = true;
            dist[d] = dist[x] + 'D';
        }

        if (check[s] == false) {
            q.push(s);
            check[s] = true;
            dist[s] = dist[x] + 'S';
        }

        if (check[l] == false) {
            q.push(l);
            check[l] = true;
            dist[l] = dist[x] + 'L';
        }

        if (check[r] == false) {
            q.push(r);
            check[r] = true;
            dist[r] = dist[x] + 'R';
        }

        if (check[e])
            return dist[e];
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int s, e;
        cin >> s >> e;

        string ans;

        ans = bfs(s, e);
        cout << ans << '\n';

    }
    return 0;
}