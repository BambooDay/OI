#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;
int n, m;
int cnt1, cnt2;
int len1, len2;
int ans = -INF;
signed main() {
	cin >> n >> m;
	if(n == 0) {
		cout << -m * m;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		len1 = m % (i + 1), len2 = i + 1 - m % (i + 1);
		cnt1 = (n - i + 1)*(n - i + 1) + (i - 1); 
		cnt2 = (m / (i + 1) + 1) * (m / (i + 1) + 1) * len1 + (m / (i + 1))*(m / (i + 1)) * len2;
		int cnt = cnt1-cnt2;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
