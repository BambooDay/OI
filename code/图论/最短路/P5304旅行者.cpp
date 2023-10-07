#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 2e6+10;
#define int long long
using namespace std;
int h[N],ne[M],node[M],val[M];
int idx = 0;
void add(int u, int v,int w){
	node[++idx] = v;
	val[idx] = w;
	ne[idx] = h[u];
	h[u] = idx;
}
int dis[N];
bool v[N];
int n, m, k;
int city[N];
int dij(int bit){
	fill(dis,dis+n+1,1e18);
	fill(v,v+n+1,0);
//	memset(dis,0x3f,sizeof dis);
//	memset(v,0,sizeof v);
	priority_queue<pair<int,int> > q;
	for(int i = 1;i <= k; i++){
		if((city[i] & (1 << bit))){
			dis[city[i]] = 0;
			q.push(make_pair(-dis[city[i]],city[i]));
		}
	}
	while(!q.empty()){
		int t = q.top().second;
		q.pop();
		if(v[t]) continue;
		v[t] = 1;
		for(int i = h[t]; i; i = ne[i]){
			int u = node[i];
			if(dis[u] > dis[t]+ val[i]){
				dis[u] = dis[t] + val[i];
				q.push(make_pair(-dis[u],u));
			}
		}
	}
	int ans = 1e18;
	for(int i = 1; i <= k; i++){
		if(!(city[i] & (1 << bit))){
			ans = min(ans,dis[city[i]]);
		}
	}
	fill(dis,dis+n+1,1e18);
	fill(v,v+n+1,0);
//	memset(dis,0x3f,sizeof dis);
//	memset(v,0,sizeof v);
	while(!q.empty()) q.pop();
	for(int i = 1;i <= k; i++){
		if(!(city[i] & (1 << bit))){
			dis[city[i]] = 0;
			q.push(make_pair(-dis[city[i]],city[i]));
		}
	}
	while(!q.empty()){
		int t = q.top().second;
		q.pop();
		if(v[t]) continue;
		v[t] = 1;
		for(int i = h[t]; i; i = ne[i]){
			int u = node[i];
			if(dis[u] > dis[t]+ val[i]){
				dis[u] = dis[t] + val[i];
				q.push(make_pair(-dis[u],u));
			}
		}
	}
	for(int i = 1; i <= k; i++){
		if((city[i] & (1 << bit))){
			ans = min(ans,dis[city[i]]);
		}
	}
	return ans;
}
void solve(){
	cin >> n >> m >> k;
	fill(h,h+1+n,0);
//	memset(h,0,sizeof h);
	idx = 0;
	for(int i = 1;i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		if(x == y || !x || !y || x > n  || y > n) continue;
		add(x,y,z);
	}
	int ans = 1e18;
	for(int i = 1;i <= k; i++) cin >> city[i];
	for(int i = 0; (1 << i) <= n; i++){
		ans = min(ans,dij(i));
	}
	cout << ans << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
} 
/*
1
6 7 3
5 1 3
2 3 5
1 4 12
5 3 2
4 6 12
4 3 7
5 6 4
1 4 6
*/
