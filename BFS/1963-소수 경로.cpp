#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

bool s[10000];
bool check[10000];
int b[10000];

int bfs(int n1, int n2) {
    queue<int> q;
    q.push(n1);
    check[n1] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int th = (x / 1000) * 1000;
        int hu;
        int te;
        int on;

        if (x % 1000 == 0)
            hu = 0;
        else
            hu = ((x % 1000) / 100) * 100;

        if (x % 100 == 0)
            te = 0;
        else
            te = ((x % 100) / 10) * 10;

        on = x % 10;

        for (int i = 0; i <= 9; i++) {
            if (check[n2] == true) {
                return b[n2];
            }

            if (i != 0) {
                if (check[x % 1000 + i * 1000] == false && s[x % 1000 + i * 1000] == false) {
                    int y = x % 1000 + i * 1000;
                    q.push(x % 1000 + i * 1000);
                    check[x % 1000 + i * 1000] = true;
                    b[x % 1000 + i * 1000] = b[x] + 1;
                }
            }

            if (check[th + x % 100 + i * 100] == false && s[th + x % 100 + i * 100] == false) {
                int y = th + x % 100 + i * 100;
                q.push(th + x % 100 + i * 100);
                check[th + x % 100 + i * 100] = true;
                b[th + x % 100 + i * 100] = b[x] + 1;
            }

            if (check[th + hu + i * 10 + on] == false && s[th + hu + i * 10 + on] == false) {
                int y = th + hu + i * 10 + on;
                q.push(th + hu + i * 10 + on);
                check[th + hu + i * 10 + on] = true;
                b[th + hu + i * 10 + on] = b[x] + 1;
            }

            if (check[th + hu + te + i] == false && s[th + hu + te + i] == false) {
                int y = th + hu + te + i;
                q.push(th + hu + te + i);
                check[th + hu + te + i] = true;
                b[th + hu + te + i] = b[x] + 1;
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i = 2; i < 10000; i++) {
        if (s[i] == false) {
            for (int j = i + i; j < 10000; j += i) {
                s[j] = true;
            }
        }
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        int ans = bfs(n1, n2);

        fill(b, b + 10000, 0);
        fill(check, check + 10000, false);

        if (ans == -1)
            cout << "Impossible" << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}