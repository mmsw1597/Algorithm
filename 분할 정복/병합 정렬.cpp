#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int a[1000];
int b[1000];

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (a[i] >= a[j]) b[k++] = a[j++];
        else b[k++] = a[i++];
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= end) {
        b[k++] = a[j++];
    }

    for (int i = start; i <= end; i++) {
        a[i] = b[i - start];
    }

}

void sort(int start, int end) {
    if (start == end)
        return;

    int mid = (start + end) / 2;

    sort(start, mid);
    sort(mid + 1, end);

    merge(start, mid, end);
}


int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}