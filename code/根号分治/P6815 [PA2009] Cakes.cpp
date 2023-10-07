#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 2.5e5+10;

using namespace std;
vector<int> e[N];
struct Edge{
	int u,v;
}E[M];
int a[N];
int n,m;
int vis[N];
int deg[N];
long long ans = 0;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i =1;i <= m; i++){
		int u,v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		if(u > v) swap(u,v);
		E[i] = {u,v};
	}		
	for(int i = 1; i <= m; i++){
		int u = E[i].u,v = E[i].v;
		if(deg[u] > deg[v]){
			e[u].push_back(v);
		}else{
			e[v].push_back(u);
		}
	}
	for(int u = 1; u <= n; u++){
		for(int v : e[u]) vis[v] = u;
		for(int v : e[u]){
			for(int k : e[v]){
				if(vis[k] == u){
					ans += max(a[u],max(a[v],a[k]));
				}
			}
		}	
	}
	cout << ans << endl;
	return 0;
}
