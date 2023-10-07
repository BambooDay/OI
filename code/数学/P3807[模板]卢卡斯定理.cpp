#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ull
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int ksm(int a, int b, int mod){
	int x = a,ans = 1;
	while(b){
		if(b & 1){
			ans = ans * x % mod;
		}
		x = x * x % mod;
		b >>= 1;
	}
	return ans;
}
ull C(int n, int m, int mod){
	if(n < m) return 0;
	int a =1, b = 1;
	for(int i = 1; i <= n; i++) a = a * i % mod;
	for(int i = 1; i <= m; i++) b = b * i % mod;
	for(int i = 1; i <= n - m; i++) b = b * i % mod;
	
	return a * ksm(b,mod-2,mod) % mod;
//	return a / b % mod;
}
ull lucas(int n, int m, int mod){
	if(n < mod && m < mod) return C(n,m,mod);
	return lucas(n/mod, m/mod,mod) * C(n % mod,m % mod,mod) % mod;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, p;
		cin >> n >> m >> p;
		cout << lucas(n+m,n, p) << endl;
	}
	return 0;
}
