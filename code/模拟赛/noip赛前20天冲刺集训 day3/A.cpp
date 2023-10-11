#include <bits/stdc++.h>
const int N = 5005;

using namespace std;
unsigned long long n,m,q;
unsigned long long sed;
unsigned long long nxt(unsigned long long mod){
	sed ^= sed << 13;
	sed ^= sed >> 7;
	sed ^= sed << 17;
	return sed % mod;
}
int a[N][N];
int c[N],r[N];
long long _17[N],_19[N];
int main(){
	cin >> n >> m >> q >> sed;
	const long long mod = 998244353;
	_17[0] = _19[0] = 1;
	for(int i = 1; i < n; i++) _17[i] = _17[i-1] * 17 % mod; 
	for(int i = 1; i < m; i++) _19[i] = _19[i-1] * 19 % mod;
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			a[i][j] = i*m+j;
		}
	}
	for(int i = 0; i < n; i++) r[i] = i;
	for(int i = 0; i < m; i++) c[i] = i;
	while(q--){
		char op;
		cin >> op;
		if(op == 'r'){
			int r1 = nxt(n),r2 = nxt(n);
			swap(r[r1],r[r2]);
		}
		if(op == 'c'){
			int c1 = nxt(m),c2 = nxt(m);
			swap(c[c1],c[c2]);
		}
		if(op == 'f'){
			int r1 =  nxt(n),c1 = nxt(m),r2 = nxt(n),c2 = nxt(m);
			swap(a[r[r1]][c[c1]],a[r[r2]][c[c2]]);
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans = (ans + _17[i]*_19[j] % mod * a[r[i]][c[j]] % mod) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}