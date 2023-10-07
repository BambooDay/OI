#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e4+10;
const int M = 1e410;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, k;
vector <int> e[N];
int top[N],hson[N],siz[N],dep[N],f[N];
void dfs1(int x, int fa){
	hson[x] = 0;
	f[x] = fa;
	siz[x] = 1;
	dep[x] = dep[fa] + 1;
	for(auto to : e[x]){
		if(to == fa) continue;
		dfs1(to,x);
		siz[x] += siz[to];
		if(siz[hson[x]] < siz[to]) hson[x] = to;
	}
	
}
void dfs2(int x, int tp){
	top[x] = tp;
	if(!hson[x]) return;
	dfs2(hson[x],tp);
	for(auto to : e[x]){
		if(to == f[x] || to == hson[x]) continue;
		dfs2(to,to);
	}
}
int v[N];
int LCA(int x, int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = f[top[x]];
	}
	if(dep[x] < dep[y]) return x;
	return y;
}
int ans;

void sum(int x){
	for(auto to : e[x]){
		if(to == f[x]) continue;
		sum(to);
		v[x] += v[to];
	}
	ans = max(ans,v[x]);
}
int main(){
	cin >> n >> k;
	for(int i = 1;i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	siz[0] = -INF;
	dfs1(1,0);
	dfs2(1,1);
	while(k--){
		int x, y;
		cin >> x >> y;
		int lca = LCA(x,y);
		v[x] += 1,v[y] += 1;
		v[lca] -= 1;
		v[f[lca]] -= 1; 
	}
	sum (1);
	cout << ans << endl;
	return 0;
}
