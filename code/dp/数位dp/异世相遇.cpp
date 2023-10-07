#include <bits/stdc++.h>
#define int long long
#define INF 0xfffffffffffffff

using namespace std;

int n, m, a[310], dp[310][310][100][2], num[100], t, sum[310];

int dfs(int l, int r, int j, bool lim) {
	if (l > r) return -2 * INF;
	if (dp[l][r][j][lim] != -INF) return dp[l][r][j][lim];
	dp[l][r][j][lim] <<= 1;
	if (j <= 1) {
		if (r - l > 1) return dp[l][r][j][lim] = -2 * INF;
		if (!lim) {
			if (l == r) return dp[l][r][j][lim] = max(0LL, a[r]);
			return dp[l][r][j][lim] = a[r];
		} else if (num[j]) {
			if (l == r) return dp[l][r][j][lim] = max(0LL, a[r]);
			return dp[l][r][j][lim] = a[r];
		}
		if (l == r) return dp[l][r][j][lim] = 0;
		return dp[l][r][j][lim] = -2 * INF;
	}
	if (!lim) {
		for (int k = l; k < r; ++k) dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, k, j - 1, false) + dfs(k + 1, r, j - 1, false) + sum[r] - sum[k]);
		dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, r, j - 1, false));
		dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, r, j - 1, false) + sum[r] - sum[l - 1]);
	} else if (num[j]) {
		for (int k = l; k < r; ++k) dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, k, j - 1, false) + dfs(k + 1, r, j - 1, true) + sum[r] - sum[k]);
		dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, r, j - 1, false));
		dp[l][r][j][lim] = max(dp[l][r][j][lim], dfs(l, r, j - 1, true) + sum[r] - sum[l - 1]);
	} else dp[l][r][j][lim] = dfs(l, r, j - 1, true);
	return dp[l][r][j][lim];
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	do {
		num[++t] = (m & 1);
		m >>= 1;
	} while (m);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) for (int k = 1; k <= t; ++k) dp[i][j][k][1] = dp[i][j][k][0] = -INF;
	cout << dfs(1, n, t, true);
	return 0;
}
