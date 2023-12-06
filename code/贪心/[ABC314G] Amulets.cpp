#include <bits/stdc++.h>
#define int long long
const int N = 3e5 + 10;

using namespace std;
int a[N], b[N];
int sum[N];
int n,m,hp; 
multiset<int> use, unused;
int ans[N];
signed main() {
	cin >> n >> m >> hp;
	for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
	int tmp = 0, cnt = 0;
	for (int i = 1; i <= m; i ++) unused.insert(0);
	for (int i = 1; i <= n; i ++) {
		int last = sum[b[i]];
		int now = sum[b[i]] + a[i];
		sum[b[i]] = now;
		if (use.count(last)) {
			use.erase(use.find(last));
			use.insert(now);
		} else {
			unused.erase(unused.find(last));
			unused.insert(now);
			tmp += a[i];
		}
		if (use.size() && unused.size() && *unused.rbegin() > *use.begin()) {
			int x = *unused.rbegin(), y = *use.begin();
			unused.erase(unused.find(x));
			unused.insert(y);
			tmp += y - x;
			use.erase(use.find(y));
			use.insert(x);
		}
		if (unused.size() && tmp >= hp) {
			int x = *unused.rbegin();
			unused.erase(unused.find(x));
			use.insert(x);
			tmp -= x;
		}
		while (cnt < use.size()) {
			ans[cnt] = i - 1;
			cnt ++;
		}
	}

	for(int i = cnt; i <= m; i++) ans[i] = n;
	for(int i = 0; i <= m; i++) cout << ans[i] << " "; 
	return 0;
}

