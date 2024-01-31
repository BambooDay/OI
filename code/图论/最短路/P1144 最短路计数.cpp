#include <bits/stdc++.h>
const int N = 1e6+10;
const int mod = 100003;
using namespace std;
vector<int> e[N];
int n,m;
int dis[N];
bool vis[N];
priority_queue<pair<int,int> > q;
void dij(){
	for(int i = 1;i <= n; i++) dis[i] = 1e9;
	dis[1] = 0;
	q.push({0,1});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v : e[u]){
			if(dis[v] > dis[u]+1){
				dis[v] = dis[u] + 1;
				q.push({-dis[v],v});
			}
		}
	} 
}
int ans[N];
int dfs(int x){
	if(ans[x]) return ans[x];
	for(int v : e[x]){
		if(dis[v]+1 == dis[x]) ans[x] = (ans[x] + dfs(v))%mod;
	}
	return ans[x];
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x,y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}	
	dij();
	ans[1] = 1;
	for(int i = 1; i <= n; i++) cout << dfs(i) << "\n";
	return 0;
}
