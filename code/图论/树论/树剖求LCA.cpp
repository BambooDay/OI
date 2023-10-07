#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5+10;
const int M = 1e410;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m, s;
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
int LCA(int x, int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = f[top[x]];
	}
	if(dep[x] < dep[y]) return x;
	return y;
}
int main(){
	cin >> n >> m >> s;
	for(int i = 1;i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	siz[0] = -INF;
	dfs1(s,0);
	dfs2(s,s);
	while(m--){
		int x,y;
		cin >> x >> y;
		cout << LCA(x,y) << endl;
	}
	return 0;
}
