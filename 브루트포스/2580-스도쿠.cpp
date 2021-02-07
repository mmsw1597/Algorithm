#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int a[9][9];
bool check_1[9][9];
bool check_2[9][9];
bool check_3[9][9];


void check(int z) {
    if (z == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }

        exit(0);
    }

    int row = z / 9;
    int col = z % 9;

    if (a[row][col] == 0) {
        int idx = (row / 3) * 3 + (col / 3);

        for (int i = 1; i <= 9; i++) {
            if (check_1[row][i] == false && check_2[idx][i] == false && check_3[col][i] == false) {
                a[row][col] = i;
                check_1[row][i] = true;
                check_2[idx][i] = true;
                check_3[col][i] = true;

                check(z + 1);
                a[row][col] = 0;
                check_1[row][i] = false;
                check_2[idx][i] = false;
                check_3[col][i] = false;

            }
        }
        return;
    }
    else
        check(z + 1);

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> a[i][j];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] != 0)
                check_1[i][a[i][j]] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[j][i] != 0)
                check_3[i][a[j][i]] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (a[i][j] != 0)
                check_2[(i / 3) * 3 + (j / 3)][a[i][j]] = true;
        }
    }
    check(0);

    return 0;
}