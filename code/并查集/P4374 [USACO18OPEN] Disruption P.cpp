#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
using namespace std;
int n,m;
vector<pair<int,int> > e[N];
struct Node{
	int u,v,w;
}road[N];
bool cmp(Node x, Node y){
	return x.w < y.w;
}
int fa[N][20];
int dep[N];
int po[N];
void dfs(int pos, int ff){
	fa[pos][0] = ff;
	dep[pos] = dep[ff]+1;
	for(int i = 1; i <= 17; i++){
		fa[pos][i] = fa[fa[pos][i-1]][i-1];
	}
	for(auto to : e[pos]){
		if(to.first == ff) continue;
		po[to.second] = to.first;
		dfs(to.first,pos);
	}
} 
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 17; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]){
			x = fa[x][i];
		}
	} 
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int father[N];
int find(int x){
	return x == father[x] ? x : father[x] = find(father[x]);
}
int ans[N];
signed main(){
	cin >> n >> m;
	for(int i = 1; i< n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	for(int i = 1; i <= m; i++){
		cin >> road[i].u >> road[i].v >> road[i].w;
	}
	dfs(1,0);
	sort(road+1,road+1+m,cmp);
	for(int i = 1;i <= n; i++) father[i] = i;
	for(int i = 1;i < n; i++) ans[po[i]] = -1;
	for(int i = 1;i <= m; i++){
		int u = road[i].u,v = road[i].v,w = road[i].w;
		int lca = LCA(u,v);
//		cout << u << " " << v << " " << w << endl; 
//		cout << lca << " ";
		for(int x = find(u);dep[x] >dep[lca];x = find(fa[x][0])){
			ans[x] = w;
			father[x] = fa[x][0];
		}
		for(int x = find(v);dep[x] >dep[lca];x = find(fa[x][0])){
			ans[x] = w;
			father[x] = fa[x][0];
		}				
	}
	for(int i = 1;i < n; i++){
//		cout << ed[i].u << " ";
		cout << ans[po[i]] << endl;
	}
	return 0;
}
