#include <bits/stdc++.h>
const int N = 1e6+10;
#define int long long
using namespace std;
vector<pair<int,int> > g[N];
int h[N];
struct edge{
	int u,v,w;
	friend bool operator<(edge x, edge y){
		return h[x.v] == h[y.v] ? x.w < y.w : h[x.v] > h[y.v];
	}
}e[N];
int tot = 0;
int sum = 1;
int ans = 0;
int fa[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool vis[N];
void bfs(){
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto to:g[u]){
			e[++tot] = {u,to.first,to.second};
			if(!vis[to.first]){
				sum++;
				vis[to.first] = 1;
				q.push(to.first);
//				cout << to.first << "xxx\n";
			}
		}
	}
}
int n,m;

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) fa[i] = i; 
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		if(h[u] >= h[v]){
			g[u].push_back({v,w});
		} 
		if(h[u] <= h[v]){
			g[v].push_back({u,w});
		} 
	}	
	bfs();
//	cout << tot << endl;
	sort(e+1,e+1+tot);
	for(int i = 1;i<= tot; i++){
		int fu = find(e[i].u),fv = find(e[i].v);
		if(fu != fv){
			fa[fu] = fv;
			ans += e[i].w;
//			cout << e[i].w << endl;
		}
	}
	cout << sum << " "<< ans; 
	return 0;
}
