#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 3000+10;
const int M = 6000+10;
const int INF = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
#define int long long
using namespace std;
int n, m;
int h[N],node[M],ne[M],idx = 0;
ll val[M];
void add(int u, int v,ll w){
	node[++idx] = v;
	ne[idx] = h[u];
	val[idx] = w;
	h[u] = idx;
}
bool in[N];
int cnt[N];
ll dis[N];
int fa[N];
int spfa(){
//	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	for(int i =1; i <= n; i++){
		q.push(i);
		in[i] = 1;
		cnt[i]=1;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = 0;
		for(int i = h[u]; ~i; i = ne[i]){
			int t = node[i];
			if(dis[t] > dis[u] + val[i]){
//			cout << t << " ";
				dis[t] = dis[u] + val[i];
				fa[t] = u;
				cnt[t] = cnt[u]+1;
				if(cnt[t] > n){
					cout << "YES ";
//					print(t);
					return t;
				} 
				if(!in[t]){
					in[t] = 1;
					q.push(t);
				}
			}
		}
	}
	cout << "NO";
	exit(0);
}
//int fa[N];
void bfs(int t){
	memset(in,0, sizeof in);
	in[t] = 1;
	while(!in[t = fa[t]]) in[t] = 1;
	vector<int> ans;
	int now = t;
	ans.push_back(now);
	while(fa[now] != t){
		now = fa[now];
		ans.push_back(now);
	}
	ans.push_back(t);
	for(int i = ans.size()-1; i >= 0; i--){
		cout << ans[i] << " ";
	}

}
signed main(){
	memset(fa,255,sizeof fa);
	memset(h,255,sizeof(h));
	cin >> n >> m;
	for(int i =1 ; i <= m; i++){
		int x, y;
		ll z;
		cin >> x >> y >> z;
		add(x,y,z);
	}
	int t = spfa();
	bfs(t);
	return 0;
}
