/*
  문제 해결 전략

  모든 수를 오름차순으로 정렬하고
  각 수를 크기가 K이하인 M개의 그룹으로 나누고 각 그룹을 내림차순으로 뒤집으면
  문제의 조건을 만족하는 수열을 만들 수 있다.

  가장 긴 증가하는 부분 수열 M은 그룹의 개수
  가장 긴 감소하는 부분 수열 K는 그룹의 최대 크기
  적어도 하나는 K 크기의 그룹을 가져야함

  구현이 굉장히 어려웠음
  접근방법은 해당 조건을 만족하는 수열을 직접 만들어보려고 시도
  수열을 거꾸로 뒤집는 전략이 필요
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