#include <bits/stdc++.h>
using namespace std;

int n,m;
int f[1 << 20][20],cnt;
vector<int> e[20];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 0; i < n; i++) f[1 << i][i] = 1;
	for (int k = 1; k < (1 << n); ++k)
		for (int i = 0; i < n; ++i) {
			if (!f[k][i]) continue;
			for (int y : e[i]) {
				if ((k & (-k)) > (1 << y)) continue;
				if (k & (1 << y)) {
					if ((k & (-k)) == (1 << y)) cnt += f[k][i];
				} else f[k | (1 << y)][y] += f[k][i];
			}
		}
	cout << (cnt - m) / 2;
	return 0;
}

