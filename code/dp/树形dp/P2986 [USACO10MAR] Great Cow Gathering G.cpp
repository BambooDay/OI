#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n;
int a[N];
vector<pair<int,int> > e[N];
int siz[N];
int f[N];
void dfs1(int pos, int fa){
	siz[pos] = a[pos];
	for(auto i : e[pos]){
		int to = i.first;
		if(to == fa) continue;
		dfs1(to,pos);
		f[1] += siz[to]*i.second; 
		siz[pos] += siz[to]; 
	}
}
int ans = 1e18;
void dfs2(int pos, int fa){
	ans = min(ans,f[pos]);
	for(auto i : e[pos]){
		int to = i.first;
		if(to == fa) continue;
		f[to] = f[pos] + (siz[1]-siz[to])*i.second - siz[to]*i.second;
		dfs2(to,pos);
	}
}
signed main(){
	cin >>n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1;i < n; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}	
	dfs1(1,0);
	dfs2(1,0);
	cout << ans << endl;
	return 0;
}
