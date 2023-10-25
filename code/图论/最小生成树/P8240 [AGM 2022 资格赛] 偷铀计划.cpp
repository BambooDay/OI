#include<bits/stdc++.h>
#define int long long
const int N = 2e5+10;
const int M = 4e5+10;

using namespace std;
int n, m;
struct edge{
	int u, v, w;
}e[N];
int h[N], ne[M], node[M], val[M],idx = 0;
void add(int u, int v,int w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int p[N],k;
int dis[N];
bool vis[N];
void dij(){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int> > q;
	for(int i = 1;i <= k; i++){
		dis[p[i]] = 0;
		q.push(make_pair(0,p[i]));
	}
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u]; i; i = ne[i]){
			int to = node[i];
			if(dis[to] > dis[u] + val[i]){
				dis[to] = dis[u] + val[i];
				q.push(make_pair(-dis[to],to));
			}
		} 
	}
}
int f[N];
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool cmp(edge x, edge y){
	return x.w > y.w; 
}
int root;
int VAL[N];
void kruscal(){
	root = n;
	for(int i = 1;i <= n<<1; i++) f[i] = i;
	sort(e+1,e+1+m,cmp);
	//int cnt = 0;
	for(int i = 1;i <= m; i++){
		int fu = find(e[i].u), fv = find(e[i].v), w = e[i].w;
		if(fu == fv) continue;
		f[fu] = ++root;
		f[fv] = root;
		add(root,fu,0);
		add(root,fv,0);
		VAL[root] = max(w-1,0ll);
		//cnt++;
		//if(cnt == n-1) break; 
	}
}
int dep[N],fa[N][20];
void dfs(int pos, int ff){
	dep[pos] = dep[ff]+1;
	fa[pos][0] = ff;
	for(int i = 1; i <= 17; i++){
		fa[pos][i] = fa[fa[pos][i-1]][i-1];
	}
	for(int i = h[pos]; i; i = ne[i]){
		int to = node[i];
		if(to == ff) continue;
		dfs(to,pos);
	} 
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 17; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
		if(fa[x][i] != fa[y][i]) x = fa[x][i],y = fa[y][i];
	} 
	return fa[x][0];
} 

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		add(e[i].u,e[i].v,e[i].w);
		add(e[i].v,e[i].u,e[i].w);
	}	
	cin >> k;
	for(int i = 1;i <= k; i++) cin >> p[i];
	dij();
	for(int i = 1; i <= m; i++){
		e[i].w = min(dis[e[i].u],dis[e[i].v]);
		//cout << e[i].w << " ";
	} 	
	//cout << endl;
	memset(h,0,sizeof h);
	idx = 0;
	kruscal();
	dfs(root,0);
	//cout << root << endl;
	int q;
	cin >> q;
	while(q--){
		int s, t;
		cin >> s >> t;
		//if(find(s) != find(t)){
		//	cout << 0 << endl;
		//}else{
		//cout << lca(s,t) << endl;
		cout << VAL[lca(s,t)] << endl;
		//}
	}
	return 0;
}
