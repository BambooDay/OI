#include <bits/stdc++.h>
#define int long long
const int N  = 3005;
using namespace std;

int n, m, top, S[N], f[N], sum[N], a[N][N];
int  ans;

signed main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++, top = 0) {
		for (int j = 1; j <= m; j++) {
			if (!a[i][j]) f[j] = i;
			while (top && f[S[top]] < f[j]) top--;
			S[++top] = j;
			ans += (sum[top] = sum[top - 1] + (i - f[S[top]]) * (S[top] - S[top - 1]));
		}
	}
	cout << ans;
	return 0;
}
