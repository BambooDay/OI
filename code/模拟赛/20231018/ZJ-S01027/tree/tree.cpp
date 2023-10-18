#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
vector<int> g[N],e[N];
int n,m,q;
int cnt;
int fa[N];
int siz[N];
void dfs(int pos, int f){
	siz[pos] = 1;
	fa[pos] = f;
	for(int to : g[pos]){
		if(to == f)continue;
		e[pos].push_back(to);
		dfs(to,pos);
		siz[pos] += siz[to];
	}
}
void add(int pos,int x){
	for(int to : g[pos]){
		if(to == fa[pos]) continue;
		e[pos+cnt-x].push_back(to+cnt-x);
		add(to,x);
	}
}
int f[N][20],dep[N];
void init(int pos){
	//cout << pos << " ";
	for(int i = 1; i <= 18; i++){
		f[pos][i] = f[f[pos][i-1]][i-1];
	}
	for(int to : e[pos]){
		dep[to] = dep[pos]+1;
		f[to][0] = pos;
		init(to);
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 18; i; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if(x == y) return f[x][0];
	for(int i = 18; i; i--){
		if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n >> m >> q;
	for(int i =1;i < n; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cnt = n;
	dfs(1,0);
	while(m--){
		int a,b;
		cin >> a >> b;
		add(a,siz[a]-1);
		e[b].push_back(a+cnt-siz[a]+1);
		cnt += siz[a];
	}
	//dep[1] = 1;
	init(1);
	while(q--){
		int x,y;
		cin >> x >> y;
		//cout << dep[x] << " " << dep[y] << " " << lca(x,y) << endl;
		cout << dep[x]+dep[y] - 2*dep[lca(x,y)] << endl;
	}
	return 0;
}