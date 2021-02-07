#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int a[10][10];
bool check_1[10][10];
bool check_2[10][10];
bool check_3[10][10];
bool tile[10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool finish = false;

void check(int z, int& cnt) {
    if (finish)
        return;

    if (z == 81) {
        cout << "Puzzle " << cnt << '\n';
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
        finish = true;
        return;
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

                for (int k = 0; k < 4; k++) {
                    int nx = row + dx[k];
                    int ny = col + dy[k];
                    if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
                        if (a[nx][ny] == 0) {
                            int idx2 = (nx / 3) * 3 + (ny / 3);
                            for (int j = 1; j <= 9; j++) {
                                if (tile[i][j] == false && tile[j][i] == false && i != j) {
                                    if (check_1[nx][j] == false && check_2[idx2][j] == false && check_3[ny][j] == false) {
                                        tile[i][j] = true;
                                        tile[j][i] = true;

                                        a[nx][ny] = j;

                                        check_1[nx][j] = true;
                                        check_2[idx2][j] = true;
                                        check_3[ny][j] = true;

                                        check(z + 1, cnt);
                                        if (finish)
                                            return;

                                        tile[i][j] = false;
                                        tile[j][i] = false;

                                        a[nx][ny] = 0;

                                        check_1[nx][j] = false;
                                        check_2[idx2][j] = false;
                                        check_3[ny][j] = false;
                                    }
                                }
                            }
                        }
                    }
                }
                check_1[row][i] = false;
                check_2[idx][i] = false;
                check_3[col][i] = false;
                a[row][col] = 0;
            }
        }
        return;
    }
    else
        check(z + 1, cnt);
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    int cnt = 1;

    while (n) {
        for (int i = 0; i < n; i++) {
            int num[2];
            char ch1, ch2;

            cin >> num[0];
            cin >> ch1 >> ch2;

            a[ch1 - 'A'][ch2 - ('1' - 1) - 1] = num[0];

            cin >> num[1];
            cin >> ch1 >> ch2;

            a[ch1 - 'A'][ch2 - ('1' - 1) - 1] = num[1];

            tile[num[0]][num[1]] = true;
            tile[num[1]][num[0]] = true;
        }

        for (int i = 1; i <= 9; i++) {
            char ch1, ch2;

            cin >> ch1 >> ch2;
            a[ch1 - 'A'][ch2 - ('1' - 1) - 1] = i;
        }

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
        check(0, cnt);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                check_1[i][j] = false;
                check_2[i][j] = false;
                check_3[i][j] = false;
                tile[i][j] = false;
                a[i][j] = 0;
            }
        }

        cnt += 1;

        cin >> n;
        finish = false;
    }
    return 0;
}