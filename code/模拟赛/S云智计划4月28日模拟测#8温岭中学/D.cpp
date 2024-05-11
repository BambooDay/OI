#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int n, L, a[N + 5];
inline int S (int x) {
	return x * (x + 1) >> 1;
}
signed main () {
	scanf ("%lld%lld", &n, &L);
	for (int i = 1; i <= n; ++ i)
		scanf ("%lld", &a[i]);
	int l = 1, r = 1e18, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		int res = 0;

		for (int i = 1; i <= n; ++ i)
			res += mid / a[i];
		if (res >= L)
			r = mid;
		else
			l = mid + 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++ i) {
		ans += S ((l - 1) / a[i]) * a[i];
		L -= (l - 1) / a[i];
	}
	ans += l * L;
	printf ("%lld\n", ans);
	return 0;
}
