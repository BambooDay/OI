#include <bits/stdc++.h>
const int N = 5e5+10;
using namespace std;
int n,m,rt;
int fa[N][25],dep[N];
vector<int> e[N];
void dfs(int pos, int f){
	dep[pos] = dep[f] + 1;
	fa[pos][0] = f;
	for(int i = 1; i <= 20; i++){
		fa[pos][i] = fa[fa[pos][i-1]][i-1];
	}
	for(int to : e[pos]){
		if(to == f) continue;
		dfs(to,pos);
	}
}
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 20; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 20; i>=0; i--){
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	}
	return fa[x][0];
}

int main(){
	cin >> n >> m >> rt;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(rt,0);
	while(m--){
		int x,y;
		cin >> x >> y;
		cout << LCA(x,y) << endl;
	}
	return 0;
}
