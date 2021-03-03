#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;



int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> nv;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nv.push_back(num);
    }

    int m;
    cin >> m;
    vector<int >mv;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        mv.push_back(num);
    }

    sort(nv.begin(), nv.end());

    for (int i = 0; i < mv.size(); i++) {
        int L = 0;
        int R = nv.size() - 1;
        int target = mv[i];
        bool btn = false;

        while (L <= R) {
            int mid = (L + R) / 2;

            if (nv[mid] == target) {
                cout << 1 << ' ';
                btn = true;
                break;
            }

            else if (nv[mid] > target) {
                R = mid - 1;
            }
            else
                L = mid + 1;
        }

        if (!btn)
            cout << 0 << ' ';
    }

    return 0;
}