#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 2e6+10;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, p;
int h[N],ne[M],node[M],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int dis[N],delta[N];
bool v[N];
bool dij(int rt){
	fill(dis,dis+n+1,INF);
	fill(v,v+n+1,0);
	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > q;
	int B = delta[rt];
	dis[rt] = 0;
	q.push(make_pair(0,rt));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(v[u]) continue;
		v[u] = 1;
		if((dis[u]+B) % p != delta[u]) return 0;
		for(int i = h[u]; i; i = ne[i]){
			int t = node[i];
			if(dis[t] > dis[u]+1){
				dis[t] = dis[u]+1;
				q.push(make_pair(dis[t],t));
			}
		}
	}
	return 1;
}
//bool g[N][N];
void solve(){
//	cin >> n >> m >> p;
	scanf("%d%d%d",&n,&m,&p);
	
	idx = 0;
	for(int i = 1; i <= n; i++){
		h[i] = 0;
		dis[i] = INF;
		v[i] = 0;
	}
	for(int i = 1; i<= m; i++){
		int x, y;
		scanf("%d%d",&x,&y);
//		cin >> x >> y;
	//	if(g[x][y] || g[y][x]) continue;
	//	g[x][y] = g[y][x] = 1;
		add(x,y);
		add(y,x);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> delta[i];
	for(int i =1;i <= n; i++){
		memset(dis,0x3f,sizeof dis);
		memset(v,0,sizeof v);
		if(dij(i)){
			if(!ans) ans = i;
			else{
				puts("zkyakioi");
//				cout << "zkyakioi" << endl;
				return;
			}
		}
	}
	if(ans){
//		cout << ans << endl;
		printf("%d\n",ans);
	}else{
		puts("zkyakioi");
//		cout<< "zkyakioi" << endl;
	}
	return ;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
