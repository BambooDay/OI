#include <bits/stdc++.h>

using namespace std;
int h[2200],ne[3000],node[3000];
int idx = 1;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
bool v[3000];
int n, m;
int rt;
int ans = 1e9;
int dis[2000];
void dfs(int u, int step){
	if(u == rt && step){
		ans = min(ans, step);
		return;
	}
	if(step >= ans) return;
	for(int i = h[u];i;i = ne[i]){
		if(v[i]) continue;
		int to = node[i];
		v[i] = v[i^1] = 1;
		dfs(to,step+1);
		v[i] = v[i^1] = 0;
	}
}

int main(){
//	cin >> n >> m;
	scanf("%d%d",&n,&m);
	if(n>500){
		cout << -2;
		exit(0);
	} 
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i = 1;i <= n; i++){
		rt = i;
		dfs(i,0);
	}
	if(ans == 1e9){
		printf("-1");
	}else printf("%d",ans);
	return 0;
}
