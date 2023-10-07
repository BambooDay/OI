#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
int n,m;
int f[300][300];
vector<pair<int,int> > e[N];
void sub1(){
	memset(f,0x3f,sizeof f);
	for(int i =1;i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		f[u][v] = w;
	}
	for(int i = 1;i <= n; i++) f[i][i] = 0;
	for(int k = 1; k <= n; k++){
		for(int i = 1;i <= n; i++){
			if(i == k) continue;
			for(int j = 1;j <= n; j++){
				if(j == i || j == k) continue;
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
				
			}
		}
	}
	for(int i = 2; i <= n; i++){
		int ans = 1e18;
		for(int j = 1; j <= n; j++){
//			if(i == j) continue;
			ans = min(ans,f[1][j] + f[i][j]);
		}
		cout << (ans >= 1e17 ? -1 : ans) << " ";
	}
}
int dis[N];
bool vis[N];
void sub2(){
	for(int i = 1;i <= n; i++){
		dis[i] = 1e18;
		vis[i] = 0;
	}
	for(int i =1;i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v,w));
	}
	priority_queue<pair<int,int> > q;
	q.push(make_pair(0,1));
	dis[1] = 0;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto j : e[u]){
			int v = j.first,w = j.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	for(int i = 2; i<= n; i++){
		cout << (dis[i] == 1e18 ? -1 : dis[i]) << " ";
	}
}
signed main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	cin >> n >> m;
	if(n <= 200) sub1();
	else sub2();	
	return 0;
}
