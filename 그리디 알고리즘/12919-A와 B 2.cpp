#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void go(string s, string t, int idx, bool& btn) {
    if (idx < 0 || idx < s.size() - 1)
        return;

    if (s == t) {
        btn = true;
        return;
    }

    if (btn)
        return;

    if (t[idx] == 'B') {
        if (t[0] == 'A')
            return;

        reverse(t.begin(), t.end());
        t.pop_back();
        go(s, t, idx - 1, btn);
    }

    else if (t[idx] == 'A' && t[0] == 'A') {
        t.pop_back();
        go(s, t, idx - 1, btn);
    }

    else if (t[idx] == 'A' && t[0] == 'B') {
        string temp_t = t;
        temp_t.pop_back();
        go(s, temp_t, idx - 1, btn);
        if (btn) {
            return;
        }
        reverse(t.begin(), t.end());
        t.pop_back();
        go(s, t, idx - 1, btn);
    }

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s, t;

    cin >> s;
    cin >> t;

    bool btn = false;

    go(s, t, t.size() - 1, btn);


    if (btn)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}