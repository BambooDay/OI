#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
vector<int> e[N];
vector<pair<int,int> > ask[N];
int ans[N];
int deg[N];
int n, m, q;
int tag[N];
signed main(){
	cin >> n >> m >> q;
	for(int i = 1;i <= m; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}	
	for(int i =1;i <= q; i++){
		int u,v;
		cin >> u >> v;
		ans[i] = deg[u];
		if(deg[u] < deg[v]) swap(u,v);
		ask[u].push_back(make_pair(v,i));
	}
	for(int u = 1; u <= n; u++){
		sort(ask[u].begin(),ask[u].end());
		for(int v : e[u]) tag[v] = u;
		int lastv = 0,lastans = 0;
		for(auto i : ask[u]){
			int v = i.first;
			if(v == lastv){
				ans[i.second] -= lastans;
				continue;
			}
			lastv = v;
			lastans = (tag[v] == u);
			for(int k : e[v]){
				if(tag[k] == u) lastans++;
			}
			ans[i.second] -= lastans;
		}
	}
	for(int i = 1;i <= q; i++){
		cout << ans[i] << endl;
	}
	return 0;
} 
