#include <bits/stdc++.h>
//#define int long long
const int N = 5005;
const int M = 5005;
const int mod = 1e9+7;
using namespace std;
struct Node{
	int v,w,id;
};
vector<Node> e[N],g[N];
int n,m;
int dis[N];
int vis[N];
int cnt[N],ans[M],in[N];
int cnt1[N];
void init(){
	for(int i = 1;i <= n; i++){
		dis[i] = 1e9;
		vis[i] = 0;
		g[i].clear();
		cnt[i] = 1;
		in[i]=0;
		cnt1[i] = 0;
	}
}
void dij(int s){
	dis[s] = 0;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	cnt1[s] = 1;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto to : e[u]){
			if(dis[to.v] == dis[u]+to.w){
				g[to.v].push_back({u,to.w,to.id});
				cnt1[to.v] = (cnt1[to.v] + cnt1[u]);
			}
			if(dis[to.v] > dis[u] + to.w){
				g[to.v].clear();
				cnt1[to.v] = cnt1[u];
				dis[to.v] = dis[u] + to.w;
				g[to.v].push_back({u,to.w,to.id});
				q.push({-dis[to.v],to.v});
			}
		}
	}
//	for(int i = 1;i <= n; i++){
//		cout << dis[i] << " ";
//		cout << g[i].size() << endl;
//	}
//	exit(0);
}

void tp(){
	queue<int> q;
	for(int i =1;i <= n; i++){
		for(auto to : g[i]){
			in[to.v]++;
		}
	}
	for(int i =1;i <= n; i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
//		cout << u << ": ";
		q.pop();
		for(auto to : g[u]){
//			cout << to.v << " ";
			cnt[to.v] = (cnt[to.v] + cnt[u])%mod;
			ans[to.id] = (ans[to.id] + cnt[u]*cnt1[to.v]%mod)%mod;
			in[to.v]--;
			if(!in[to.v]) q.push(to.v);
		}
//		cout << endl;
	}
//	for(int i =1;i <= n; i++) cout << cnt[i] << endl;
//	exit(0);
}
signed main(){
	cin >> n >> m;
	for(int i =1;i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w,i});
	}
	for(int i = 1; i <= n; i++){
		init();
		dij(i);
		tp();
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << endl; 
	}
	return 0;
}
