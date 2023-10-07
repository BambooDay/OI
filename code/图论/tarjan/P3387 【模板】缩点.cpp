#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4+10;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[M],node[M],val[N];
int idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
} 
int u[M],v[M];
bool in[N];
stack<int> st;
int scc[N],cnt = 0;
int dfn[N],low[N];
int tot = 0;
int val1[N];
void tarjan(int pos){
//	cout << pos << ' ';
	in[pos] = 1;
	dfn[pos] = ++tot;
	low[pos] = dfn[pos];
	st.push(pos);
	for(int i = h[pos];i;i = ne[i]){
		int to = node[i];
		if(!dfn[to]){
			tarjan(to);
			low[pos] = min(low[pos],low[to]);
		}else{
			if(in[to]) low[pos] = min(low[pos],dfn[to]);
			
		}
	}
	if(dfn[pos] == low[pos]){
//	cout << pos << " ";
		scc[pos] = ++cnt;
		while(st.top() != pos){
			scc[st.top()] = cnt;
			in[st.top()] = 0;
			val1[cnt] += val[st.top()]; 
			st.pop();
		}
		val1[cnt] += val[pos];
		in[pos] = 0;
		st.pop();
	}
}
int d[N];
int dp[N];
int ans = 0;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> val[i];
	for(int i = 1;i <= m; i++){
		cin >> u[i] >> v[i];
		add(u[i],v[i]);
	}
	for(int i = 1;i <= n; i++){

		if(!dfn[i]) tarjan(i);
	}
	memset(h,0,sizeof h);
	idx = 0;
	for(int i = 1;i <= m; i++){
		int x = scc[u[i]],y = scc[v[i]];
		if(x == y) continue;
		add(x,y);
		++d[y];
	}
	queue<int> q;
	for(int i = 1;i <= cnt; i++){
		if(!d[i]) q.push(i);
	}
	while(!q.empty()){
		int t = q.front();q.pop();
		dp[t] += val1[t];
		for(int i = h[t]; i; i = ne[i]){
			int k = node[i];
			dp[k] = max(dp[k],dp[t]);
			if(!--d[k]) q.push(k);
		}
		ans = max(ans, dp[t]);
	}
	cout << ans;
	return 0;
}
