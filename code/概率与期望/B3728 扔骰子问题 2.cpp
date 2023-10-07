#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int f[1005][6005], n, ts[1005], pwre[1005];
int ksm(int x, int y) {
	int r = 1;
	while (y) {
		if (y & 1)r = r * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return r;
}
signed main() {
	f[0][0] = 1;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j <= i * 6; j++) {
			for (int k = 1; k <= 6; k++) {
				f[i + 1][j + k] = (f[i + 1][j + k] + f[i][j]) % mod;
			}
		}
	}
	pwre[0] = 1;
	int re6 = ksm(6, mod - 2);
	
	for (int i = 1; i <= 1000; i++) pwre[i] = pwre[i - 1] * re6 % mod; 
//	cin >> n;
	scanf("%lld",&n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l, r;
//		cin >> l >> r;
		scanf("%lld%lld",&l,&r);
		ans ^= f[l][r] * pwre[l] % mod;
	}
//	cout << ans;
	printf("%lld",ans);
	return 0;
}
