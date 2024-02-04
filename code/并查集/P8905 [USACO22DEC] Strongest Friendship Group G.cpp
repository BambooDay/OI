#include <bits/stdc++.h>
const int N = 1e5+7;
#define fi first
#define se second
#define int long long
using namespace std;
int n,m;
set<int> g[N];
set<pair<int,int> > q;
vector<pair<int,int> > edge[N];
int deg[N];
int fa[N],siz[N];
int Siz;

int find(int x) {
	while(x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}
void merge(int u,int v) {
	int fu = find(u),fv = find(v);
	if(fu == fv)return;
	fa[fv] = fu;
	siz[fu] += siz[fv];
	Siz = max(Siz,siz[fu]);
}

signed main() {
	cin >> n;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
		deg[u]++;
		deg[v]++;
	}
	for(int i = 1; i <= n; i++) q.insert({deg[i],i});
	int cnt = 1;
	for(; !q.empty(); cnt++) {
		while(!q.empty() && (*q.begin()).first < cnt) {
			int u = (*q.begin()).second;
			q.erase(q.begin());
			for(auto v : g[u]) if(g[v].find(u) != g[v].end()){
				q.erase({deg[v],v});
				g[v].erase(u);
				deg[v]--;
				edge[cnt].push_back({u,v});
				q.insert({deg[v],v});
			}
			deg[u] = 0;
			g[u].clear();
		}
	}
	for(int i = 1; i <= n; i++) fa[i] = i,siz[i] = 1;
	int ans = 0;
	for(int i = cnt-1; i >= 0; i--) {
		if(i!=cnt-1) ans = max(ans,1ll*Siz*i);
		for(auto e : edge[i]) {
			merge(e.fi,e.se);
		}
	}
	cout << ans;
	return 0;
}
