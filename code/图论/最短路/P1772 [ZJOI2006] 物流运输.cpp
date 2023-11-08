#include<bits/stdc++.h>
#define ll long long
using namespace std;
int d,cnt,head[25],dis[25],vis[25];
ll co[105][105],dp[105];
int n,m,k,ee,cl[25][105];
vector<pair<int,int> > e[25];

void dij() {
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int> > q;
	dis[1] = 0;
	q.push({0,1});
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(auto to : e[x]) {
			int v = to.first;
			if(vis[v]) continue;
			if(dis[v] > dis[x]+to.second) {
				dis[v] = dis[x]+to.second;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main() {
	cin >> n >> m >> k >> ee;
	for(int i = 1; i <= ee; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	cin >> d;
	for(int i = 1; i <= d; i++) {
		int t,x,y;
		cin >> t >> x >> y;
		for(int j = x; j <= y; j++) cl[t][j] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			memset(vis,0,sizeof vis);
			for(int r = i; r <= j; r++) {
				for(int l = 1; l <= m; l++) {
					if(cl[l][r]) vis[l] = 1;
				}
			}
			dij();
			co[i][j] = dis[m];
		}
	memset(dp,0x3f,sizeof dp);
	for(int i = 1; i <= n; i++) {
		dp[i]=1ll*co[1][i]*i;
		for(int j = i-1; j; j--)
			dp[i]=min(dp[i],dp[j]+co[j+1][i]*(i-j)+k);
	}
	printf("%lld",dp[n]);
	return 0;
}

