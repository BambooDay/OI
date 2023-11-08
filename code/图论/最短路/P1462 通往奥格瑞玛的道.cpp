#include <bits/stdc++.h>
#define int long long
const int N = 1e4+10;
 
using namespace std;
int n,m,b;
int f[N];
vector<pair<int,int> > e[N];
int dis[N];
bool vis[N];
bool check(int mid){
	fill(dis,dis+n+1,1e18);
	fill(vis,vis+n+1,0);
	if(mid < f[1]) return 0;
	dis[1] = 0;
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	while(!q.empty()){
		int u = q.top().second;
//		cout << u << endl;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto i:e[u]){
			int to = i.first,w = i.second;
			if(f[to] > mid) continue;
			if(dis[to] > dis[u]+w && dis[u]+w <= b){
				dis[to] = dis[u]+w;
				q.push({-dis[to],to});
			} 
		}
	}
	return dis[n] != 1e18;
}

signed main(){
	cin >> n >> m >> b;
	for(int i = 1;i <= n; i++) cin >> f[i];
	for(int i = 1;i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}	
//	check(10);
//	return 0;
	int l = 1, r = 1e9;
	int ans = -1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else l = mid+1;
	}
	if(ans == -1) puts("AFK");
	else cout << ans << endl;
	return 0;
}
