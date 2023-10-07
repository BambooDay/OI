#include <bits/stdc++.h>
const int N = 1e5+100;
const int M = 2e5+10;

using namespace std;
int h[N],node[M],ne[M],val[M];
int idx;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u];
	val[idx] = w;
	h[u] = idx;
}
int dis[N],vis[N],n,m;

void dij(int st){
	fill(dis,dis+n+1,1e9);
	dis[st] = 0;
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,st));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u] ;i; i = ne[i]){
			int v = node[i],w = val[i];
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}	
} 
int s;
int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	dij(s);
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	return 0;
}
