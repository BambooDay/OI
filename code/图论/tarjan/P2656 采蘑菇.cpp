#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int M = 2e5+10;
using namespace std;
struct road{
	int u,v,w,k;
}path[M];
int n,m,s;
vector<int> e[N];
stack<int> st;
int belong[N],scc;
int dfn[N],low[N],cnt;
void tarjan(int pos){
	dfn[pos] = low[pos] = ++ cnt;
	st.push(pos);
	for(int to : e[pos]){
		if(!dfn[to]){
			tarjan(to);
			low[pos] = min(low[pos],low[to]);
		}else{
			if(!belong[to]) low[pos] = min(low[pos],dfn[to]);
		}
	} 
	if(low[pos] == dfn[pos]){
		scc++;
		while(st.top() != pos){
			belong[st.top()] = scc;
			st.pop();
		}
		belong[pos] = scc;
		st.pop();
	}
}
int sum[N],dis[N];
vector<pair<int,int> > g[N];
bool in[N];
void spfa(){
	queue<int> q;
	memset(dis,-1,sizeof dis);
	dis[belong[s]] = sum[belong[s]];
	q.push(belong[s]);
	in[belong[s]] = 1;
	while(!q.empty()){
		int u = q.front();
		in[u] = 0;
		q.pop();
		for(auto v : g[u]){
			if(dis[v.first] < dis[u] + v.second + sum[v.first]){
				dis[v.first] = dis[u] + v.second + sum[v.first];
				if(!in[v.first]){
					in[v.first] =1;
					q.push(v.first);
				}
			}
		}
	} 
}
signed main(){
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		int u,v,w;
		double k;
		cin >> u >> v >> w >> k;
		path[i] = {u,v,w,k*10};
		e[u].push_back(v);
//		cout << path[i].k << endl;
	}	
	cin >> s;
	for(int i = 1;i <= n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	for(int i = 1; i <= m; i++){
		int u = path[i].u,v = path[i].v,w = path[i].w,k = path[i].k;
		if(belong[u] == belong[v]){
			while(w){
				sum[belong[u]] += w;
				w = w *k / 10;
//				cout << w << endl;
			}
		}else{
			g[belong[u]].push_back(make_pair(belong[v],w));
		}
	}
//	for(int i = 1;i <= scc; i++) cout << sum[i] << endl;
//	return 0;
	spfa();
	int ans = -1;
	for(int i = 1; i <= scc; i++){
		ans = max(ans,dis[i]);
	}
	cout << ans;
	return 0;
}
