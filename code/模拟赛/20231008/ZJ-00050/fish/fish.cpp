#include <bits/stdc++.h>
#define int long long
const int N = 1e6+10;
const int mod = 1e9+7;

using namespace std;
int n, m;
struct edge{
	int u,v;
}e[N];
int ans = 0;
int deg[N];
void dfs(int step, int cnt){
	if(step > m){
		for(int i = 1; i <= n; i++){
			if(deg[i]) return;
		}
		ans += cnt*cnt % mod;
		ans %= mod;
		return;
	}
	dfs(step+1,cnt);
	deg[e[step].u] ^= 1;
	deg[e[step].v] ^= 1;
	dfs(step+1,cnt+1);
	deg[e[step].u] ^= 1;
	deg[e[step].v] ^= 1;
}
signed main(){
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v;
	}	
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
