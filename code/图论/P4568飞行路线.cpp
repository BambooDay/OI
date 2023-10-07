#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4 * 11+10;
const int M = 5e4*11*2+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int h[N],ne[M],node[M],val[M],idx = 0;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int n, m, k,st,en;
int dis[N];
bool v[N];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[st] = 0;
	priority_queue <pair<int, int>, vector< pair<int,int> > ,greater<pair<int,int> > > q;
	q.push(make_pair(0,st));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(v[u]) continue;
		v[u] = 1;
		for(int i = h[u]; i;i = ne[i]){
			int t = node[i];
			if(dis[t] > dis[u] + val[i]){
				dis[t] = dis[u] + val[i];
				q.push(make_pair(dis[t],t));
			}
		}
	}
}
int main(){
	cin >> n >> m >> k >> st >> en;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		for(int j = 0; j <= k; j++){
			add(j*n + a, j * n + b, c);
			add(j*n + b, j * n + a, c);
		}
		for(int j = 0; j < k; j++){
			add(j*n + a, (j + 1) * n + b,0);
			add(j*n + b, (j + 1) * n + a,0);
		}
	}
	dijkstra();
	int ans = INF;
	
	for(int i = 0; i <= k; i++){
//		cout << dis[i*n+en] << endl;
		ans = min(ans,dis[i*n+en]);
	}
	cout << ans<< endl;
	return 0;
}
