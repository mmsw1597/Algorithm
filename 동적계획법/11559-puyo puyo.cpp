#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char a[12][6];
bool check[12][6];
int u[4] = { 0,0,1,-1 };
int t[4] = { 1,-1,0,0 };

bool bfs(int ux, int uy, char ch, int &cnt) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> w;
	q.push(make_pair(ux, uy));
	w.push(make_pair(ux, uy));
	check[ux][uy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + u[i];
			int ny = y + t[i];

			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
				if (a[nx][ny] == ch && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny)); 
					w.push(make_pair(nx, ny));					
				}
			}
		}
	}
	
	if (w.size() >= 4) {
		while (!w.empty()) {
			int wx = w.front().first;
			int wy = w.front().second;
			a[wx][wy] = '.';
			w.pop();
		}
		return true;
	}

	return false;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	queue <pair<int, int>> q;
	int cnt = -1;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}

	int btn = 0;
	bool c = false;

	do {
		btn = 0;
		c = false;
		cnt++;

		memset(check, 0, sizeof(check));

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] != '.' && check[i][j] == false) {
					c = bfs(i, j, a[i][j], cnt);
					if (c) {
						btn++;
					}
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			for (int j = 11; j > 0; j--) {
				if (a[j][i] == '.'){
					for (int k = j - 1; k >= 0; k--) {
						if (a[k][i] != '.') {
							a[j][i] = a[k][i];
							a[k][i] = '.';
							break;
						}
					}
				}
			}
		}
	} while (btn);


	cout << cnt << '\n';
}