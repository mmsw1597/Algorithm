/*
  ���� �ذ� ����

  ��� ���� ������������ �����ϰ�
  �� ���� ũ�Ⱑ K������ M���� �׷����� ������ �� �׷��� ������������ ��������
  ������ ������ �����ϴ� ������ ���� �� �ִ�.

  ���� �� �����ϴ� �κ� ���� M�� �׷��� ����
  ���� �� �����ϴ� �κ� ���� K�� �׷��� �ִ� ũ��
  ��� �ϳ��� K ũ���� �׷��� ��������

  ������ ������ �������
  ���ٹ���� �ش� ������ �����ϴ� ������ ���� �������� �õ�
  ������ �Ųٷ� ������ ������ �ʿ�
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n, m, k;

int main() {
    cin >> n >> m >> k;

    if (n + 1 < m + k) {
        cout << -1 << '\n';
        return 0;
    }

    if (n > m * k) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> v;

    n -= k;
    int num = 1;
    int idx = k;

    for (int i = k; i >= 1; i--) {
        v.push_back(i);
    }

    while (m != num) {
        for (int i = 1; i <= k; i++) {
            int a = (n % i > 0) ? 1 : 0;
            if ((n / i) + a + num > m)
                continue;
            else if ((n / i) + a + num <= m) {
                n -= i;
                int temp = 0;
                idx += i;
                while (temp != i) {
                    v.push_back(idx - temp);
                    temp++;
                }
                num += 1;
                break;
            }
            else if (((n / i) + num == m) && a == 0) {
                int b = num;
                for (int j = 0; j < m - b; j++) {
                    idx += i;
                    for (int k = 0; k < i; k++) {
                        v.push_back(idx - k);
                    }
                    num += 1;
                }
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    return 0;
}