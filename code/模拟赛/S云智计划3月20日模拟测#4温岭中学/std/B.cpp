#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
long long ksm(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1LL * res * x % mod;
		x = 1LL * x * x % mod;
		y >>= 1;
	}
	return res;
}
int mul[maxn << 1];
int calc(int x, int y) {
	return 1LL * mul[x] * ksm(mul[y], mod - 2) % mod * ksm(mul[x - y], mod - 2) % mod;
}
int a[maxn];
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i++) cin >> a[i];
	mul[0] = 1;
	for(int i = 1; i < (maxn << 1); i++) mul[i] = 1LL * mul[i - 1] * i % mod;
	int ans = 0;
	for(int i = 1; i <= n + 1; i++) (ans += calc(i + a[i] - 1, i)) %= mod;
	printf("%d", ans);
	return 0;
}