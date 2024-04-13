#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	cin >> T;
	while (T--) {
		int a1, b1, a2, b2, n;
		cin >> a1 >> b1 >> a2 >> b2 >> n;
		int ans = 0;
		for (int l = 1, r, i; l <= a1 + 1; l = r + 1) {
			i = a1 / l;
			r = i ? a1 / i : 1e9;
			int j = i + b1 - b2;
			if (j < 0 || j > a2)
				continue;
			int l2 = a2 / (j + 1) + 1, r2 = j ? a2 / j : 1e9;
			l2 = max(l, l2);
			r2 = min(r, r2);
			r2 = min(n, r2);
			if (l2 <= r2)
				ans += r2 - l2 + 1;
		}
		cout << ans << '\n';
	}
}

