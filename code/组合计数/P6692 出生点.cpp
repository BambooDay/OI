#include <bits/stdc++.h>
#define int __int128
const int N = 5e5 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int  mod = 1e9 + 7;
using namespace std;
int read(){
	int ans = 0, f =1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f = -1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans = ans*10+ch-'0';
		ch =getchar();
	}
	return ans * f;
}
struct Node {
	int x, y;
} obs[N];
bool cmpx(Node a, Node b) {
	return a.x < b.x;
}
bool cmpy(Node a, Node b) {
	return a.y < b.y;
}
int sum(int n) {
	if (n % 2 == 0) return (n / 2 * (n + 1)) % mod;
	else return ((n + 1) / 2 * n) % mod;
}
int mul(int n) {
	if (n % 2 == 0) return (n / 2 * (n + 1) * (2 * n + 1) / 3) % mod;
	else return ((n + 1) / 2 * n * (2 * n + 1) / 3) % mod;
}
int n, m;
int k;
int ans = 0;
int f[N], g[N];
signed main() {
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= k; i++) {
		obs[i].x = read();
		obs[i].y = read();
	}
	ans += m * m * n % mod * sum(n - 1);
	ans %= mod;
	ans -= m * m % mod * mul(n - 1);
	ans = (ans%mod + mod) % mod;
	ans += m * n * n % mod * sum(m - 1);
	ans %= mod;
	ans -= n * n % mod * mul(m - 1);
	ans = (ans%mod + mod) % mod;	
	for (int i = 1; i <= k; i++) {
		ans -= sum(obs[i].x - 1) * m % mod + m * sum(n - obs[i].x) % mod;
		ans = (ans%mod + mod) % mod;
		ans -= sum(obs[i].y - 1) * n % mod + n * sum(m - obs[i].y) % mod;
		ans = (ans%mod + mod) % mod;
	}
	sort(obs + 1, obs + k + 1, cmpx);
	for (int i = 2; i <= k; i++) {
		f[i] = f[i - 1] + (i - 1) * (obs[i].x - obs[i - 1].x) % mod;
		f[i] %= mod;
		ans = ans + f[i];
		ans %= mod;
	}
	sort(obs + 1, obs + k + 1, cmpy);
	for (int i = 2; i <= k; i++) {
		g[i] = g[i - 1] + (i - 1) * (obs[i].y - obs[i - 1].y) % mod;
		g[i] %= mod;
		ans = ans + g[i];
		ans %= mod;
	}
	long long an = ans % mod;
	cout << an;	
	return 0;
}
//m^2*n*((n-1)n/2))-m^2*(n(n+1)(2n+1)/6)
