#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
int f[N][20];
vector<int> e[N];
int dis[N];
void dfs(int pos, int fa){
	dis[pos] = dis[fa]+1;
	f[pos][0] = fa;
	for(int i = 1;i <= 19; i++){
		f[pos][i] = f[f[pos][i-1]][i-1];
	}
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs(to,pos);
	}
}
int lca(int x, int y){
	if(dis[x] < dis[y]) swap(x,y);
	for(int i = 19; i >= 0; i--){
		if(dis[f[x][i]] >= dis[y])x = f[x][i];
	} 
	if(x == y) return x;
	for(int i = 19; i >= 0; i--){
		if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	}
	return f[x][0];
}
int n;
long long ans = 0;
int d(int x, int y){
	return dis[x] + dis[y] - 2* dis[lca(x,y)];
}
int main(){
	freopen("ringcount.in","r",stdin);
	freopen("ringcount.out","w",stdout);
	cin >> n;
	for(int i = 1;i < n; i++){
		int f;
		cin >> f;
		e[f].push_back(i+1);
		e[i+1].push_back(f);
	}
	dfs(1,0);
	for(int u = 1; u <= n; u++){
		for(int v = u+1; v <= n; v++){
			for(int w = v+1; w <= n; w++){
				if(d(u,v) == d(v,w) && d(v,w) == d(w,u)) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}