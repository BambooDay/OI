#include <bits/stdc++.h>
#define int long long
const int N = 1e6+10;

using namespace std;
int n;
int pri[N],cnt,siz[N],dp[N];
map<long long,int> vis,id;
int m,dfn;
int dfs(int x){
	if(id.count(x)) return id[x];
//	cout << x << endl;
	id[x] = ++dfn;
	dp[id[x]] = 1e18;
	for(int i = 1; i <= cnt && pri[i] <= sqrt(x); i++){
		if(x % pri[i] == 0){
			int ls = dfs(pri[i]),rs = dfs(x / pri[i]);
			siz[id[x]] = siz[ls] + siz[rs] + 1;
			dp[id[x]] = min(dp[id[x]], (siz[ls]+1)*(siz[rs]+1)*x + dp[ls] + dp[rs]);
		}
	}
	if(!siz[id[x]]) siz[id[x]] = 1,dp[id[x]] = x;
	if(vis.count(x)) dp[id[x]] = 1e18;
	return id[x];
}
signed main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		vis[x] = 1;
	}
	if(vis.count(n)){
		cout << "-1" << endl;
		return 0; 
	}
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){
			pri[++cnt] = i;
		}
	}
	dfs(n);
	cout << (dp[id[n]]  == 1e18 ? -1 : dp[id[n]]);
	return 0;
}
