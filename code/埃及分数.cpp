#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int h[N],e[M],ne[M],idx;
void add(int u,int v){
	e[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int n, m,ans[N];
void dfs(int ma,int node){
	if(ans[node]) return;
	ans[node] = ma;
	for(int i = h[node];i != -1; i = ne[i]){
		if(ans[e[i]]) continue;
		dfs(ma,e[i]);
	}
}
int main(){
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	for(int i = 1; i <= m ; i++){
		int u,v;
		cin >> u >> v;
		add(v,u);
	}
	for(int i = n; i > 0; i--){
		dfs(i,i);
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

