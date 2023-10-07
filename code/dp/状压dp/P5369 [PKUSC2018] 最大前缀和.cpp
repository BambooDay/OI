#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
int sum[1<<21],f[1<<21][2],g[1<<21];
int n, a[21];

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1;i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				sum[i] += a[j+1];
			}
		}
	}
	for(int i =1;i <= n; i++){
		if(a[i] < 0){
			f[1 << (i-1)][0] = 1;
		}else{
			f[1 << (i-1)][1] = 1;
		}
	}
	for(int i = 1;i < (1 << n); i++){
		int s = i;
		for(int j = 0; j < n; j++){
			if(s & (1 << j)) continue;
			int t = s | (1 << j);
			if(sum[t] >= 0){
				f[t][1] = (f[t][1] + f[s][1]) % mod;
			}else{
				f[t][0] = (f[t][0] + f[s][1]) % mod;
			}
		}
	}	
	g[0] = 1;
	for(int i = 0; i < ( 1 << n); i++){
		int s = i;
		if(!g[s]) continue;
		for(int j = 0; j < n; j++){
			if(s & (1 << j)) continue;
			int t = (s | (1 << j));
			if(sum[t] < 0) g[t] = (g[t] + g[s]) % mod;
		}
	}
	int u = (1 << n) -1;
	int ans = 0;
	for(int i = 1; i <= u; i++){
		ans = (ans + (sum[i] % mod + mod) % mod * (f[i][0]+f[i][1]) % mod*g[u^i] % mod) % mod;
	}
	cout << ans;
	return 0;
}
