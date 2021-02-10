#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int a, b;
int ans = -1;

void bfs(long long int a, long long int b) {
    queue<pair<long long int, long long int>> q;
    q.push(make_pair(a, 1));

    while (!q.empty()) {
        pair<long long int, long long int> x = q.front();
        if (x.first == b) {
            ans = x.second;
            return;
        }

        q.pop();

        if (x.first * 2 <= b) {
            q.push(make_pair(x.first * 2, x.second + 1));
        }

        if ((x.first) * 10 + 1 <= b) {
            q.push(make_pair((x.first) * 10 + 1, x.second + 1));
        }

    }


}


int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> a >> b;

    bfs(a, b);

    cout << ans << '\n';
    return 0;
}