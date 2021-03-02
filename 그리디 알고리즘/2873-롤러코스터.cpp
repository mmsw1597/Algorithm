/*
  ���� �ذ� ����

  ���� �̷θ� Ǯ�鼭 ¦�� Ȧ���� ���� ����� ���� �з��س�
  ������� ������

  �ð��ʰ��� �߻�, 4*n*m�� �ð����⵵�� �����ߴµ� �ƴѰ���
  �̷���� ���� �ٸ������ �����س�����

  A������ �����̴°��� �ƴ� ������ B������ �����δٰ� �����ϴ� �����
  ������
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int r, c;
int a[1000][1000];
bool check[1000][1000];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> r >> c;
    int x = 0;
    int y = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    int min = a[0][1];
    int btn = 1;

    for (int i = 0; i < r; i++) {
        for (int j = btn; j < c; j += 2) {
            if (min > a[i][j]) {
                min = a[i][j];
                x = i;
                y = j;
            }
        }
        btn = 1 - btn;
    }

    check[x][y] = true;

    if (r % 2 == 1) {
        for (int k = 0; k < r / 2; k++) {
            for (int i = 0; i < c - 1; i++)
                cout << 'R';
            cout << 'D';
            for (int i = 0; i < c - 1; i++)
                cout << 'L';
            cout << 'D';
        }
        for (int i = 0; i < c - 1; i++)
            cout << 'R';
    }

    else if (r % 2 == 0 && c % 2 == 1) {
        for (int k = 0; k < c / 2; k++) {
            for (int i = 0; i < r - 1; i++)
                cout << 'D';
            cout << 'R';
            for (int i = 0; i < r - 1; i++)
                cout << 'U';
            cout << 'R';
        }
        for (int i = 0; i < r - 1; i++)
            cout << 'D';
    }
    else {
        int x1 = 0;
        int y1 = 0;
        int x2 = r - 1;
        int y2 = c - 1;

        string start;
        string end;

        while (x2 - x1 > 1) {
            if (x1 + 1 < x) {
                for (int i = 0; i < c - 1; i++)
                    start += 'R';
                start += 'D';
                for (int i = 0; i < c - 1; i++)
                    start += 'L';
                start += 'D';

                x1 += 2;
            }

            if (x2 - 1 > x) {
                for (int i = 0; i < c - 1; i++)
                    end += 'R';
                end += 'D';
                for (int i = 0; i < c - 1; i++)
                    end += 'L';
                end += 'D';

                x2 -= 2;
            }
        }

        while (y2 - y1 > 1) {
            if (y1 + 1 < y) {
                start += 'D';
                start += 'R';
                start += 'U';
                start += 'R';
                y1 += 2;
            }
            if (y2 - 1 > y) {
                end += 'D';
                end += 'R';
                end += 'U';
                end += 'R';
                y2 -= 2;
            }
        }
        if (x1 == x) {
            start += 'D';
            start += 'R';
        }
        else if (x2 == x) {
            end += 'D';
            end += 'R';
        }

        reverse(end.begin(), end.end());
        string ans = start + end;
        cout << ans << '\n';
    }

    return 0;
}