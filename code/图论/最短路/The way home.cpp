#include <bits/stdc++.h>
const int N = 810;
const int M = 3010;
#define ll long long
using namespace std;
int h[N],ne[M],node[M];
ll val[M],idx;
void add(int u, int v, ll w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int n, m, p, vis[N][N];
struct Node{
	int u, mx;
	ll t,c;
	bool operator < (const Node & x)const{
		return t == x.t ? c < x.c : t > x.t;
	}
};
ll ans,a[N];
void solve(){
	priority_queue<Node> q;
	memset(vis,0,sizeof vis);
	memset(h,0,sizeof h);
	idx = 0;
	ans = 1e18;
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	q.push({1,1,0,p});
	while(!q.empty()){
		Node fr = q.top();
		q.pop();
		int u = fr.u,mx = fr.mx;
		if(vis[u][mx]) continue;
		vis[u][mx] = 1;
		if(u == n) ans = min(ans,fr.t);
		for(int i = h[u];i;i = ne[i]){
			int v = node[i],w = val[i],mxj = (a[v] > a[mx] ? v : mx);
			ll t = (max(0ll,w - fr.c) + a[mx] -1) / a[mx];
			q.push({v,mxj,fr.t+t,fr.c+t*a[mx]-w});
		}
	}
	printf("%lld\n",ans == 1e18 ? -1 : ans);
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
