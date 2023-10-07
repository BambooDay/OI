#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int mod = 1e9+7;
using namespace std;
int n, k, q;
int a[N];
int jump_to[N][45],jump_val[N][45];

signed main(){
//	freopen("jump.in","r",stdin);
	cin >> n >> k >> q;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		a[i] = (a[i]%mod+mod)%mod; 
	} 
	for(int i = 1;i <= n; i++){
		jump_to[i][0] = (i+k) % n + 1;
		jump_val[i][0] = a[(i+k)%n + 1]; 
	}	
	for(int i = 1; i <= 40; i++){
		for(int j = 1; j <= n; j++){
			jump_to[j][i] = jump_to[jump_to[j][i-1]][i-1];
			jump_val[j][i] = ((jump_val[j][i-1] + jump_val[jump_to[j][i-1]][i-1]) % mod + mod)%mod;
		}
	}
	while(q--){
		int x, m;
		cin >> x >> m;
		int sum = a[x];
		m--;
		for(int i = 40; i >= 0; i--){
			if((1ll << i) <= m){
//				cout  << i << endl; 
				sum = ((sum + jump_val[x][i]) % mod+mod)%mod;
				x = jump_to[x][i];
				m -= (1ll << i);
			}
		}
		cout << sum << " ";
	}
	return 0;
}
/*
4 1 4
1 2 3 4
1 1
1 2
1 3
1 4
*/
