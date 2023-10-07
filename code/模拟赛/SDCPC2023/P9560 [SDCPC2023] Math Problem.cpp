#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18 + 7;

int T;
ll n, m, k, a, b;

int main() {

	cin >> T;
	while (T --) {
		cin >> n >> k >> m >> a >> b;
		if (n % m == 0) {
			cout << "0\n";
			continue;
		}
		if (k == 1) {
			cout << "-1\n";
			continue;
		}
		ll ans = INF, cost = 0;
		while (true) {
			ll l = n % m, len = 1;
			for (int i = 0; ; i++) {
				ll remain = (m - l) % m;
				if (remain < len) {
					ans = min(ans, cost + i * a);
					break;
				}
				l = l * k % m;
				len *= k;
			}
			if (n == 0) break;
			n /= k;
			cost += b;
		}
		cout << ans << endl;
//		while(n)
//		{
//			ll l = n % m, r = n % m, s = 0;
//			while(1)
//			{
//				if(r - l + 1 >= m || r % m < l % m) break;
//				s += a; l *= k; r = r * k + k - 1;
//			}
//			n /= k;
//			ans = min(ans, cost + s);
//			cost += b;
//		}
//		cout << min(ans, cost) << "\n";
	}
	return 0;
}
