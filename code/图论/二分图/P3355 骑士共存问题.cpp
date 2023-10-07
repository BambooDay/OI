#include<bits/stdc++.h>
using namespace std;


int n, m, match[40010], ans;
bool vis[40010], mp[210][210];
vector<int> e[40010];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
bool find(int x) {
	for (int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (vis[y] == 0) {
			vis[y] = 1;
			if (match[y] == 0 || find(match[y]) == 1) {
				match[y] = x;
				return 1;
			}
		}
	}
	return 0;
}

int get(int x, int y) {
	return (x - 1) * n + y;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		mp[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if ((i + j) % 2 || mp[i][j])
				continue;
			for (int k = 0; k < 8; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx > 0 && ny > 0 && nx <= n && ny <= n && mp[nx][ny] == 0)
					e[get(i, j)].push_back(get(nx, ny));
			}
		}
	for (int i = 1; i <= n * n; i++) {
		memset(vis, 0, sizeof(vis));
		if (find(i))
			ans++;
	}
	cout << n*n - ans - m;
	return 0;
}
