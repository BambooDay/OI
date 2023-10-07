#include <bits/stdc++.h>
const int N = 3003;
#define ll long long
using namespace std;
int n,m,a[N],w[N],b[N],siz[N];
int f[N][N],r[N];
ll g[N][N],c[N];
vector<int> e[N];
void init(){
	memset(f,0,sizeof f);
	memset(g,0xf3,sizeof g);
	for(int i = 1;i <= n; i++) e[i].clear();
}
void dfs(int pos, int fa){
	f[pos][1] = 0,g[pos][1] = a[pos];
	siz[pos] = 1;
	for(int v: e[pos]){
		if(v == fa) continue;
		dfs(v,pos);
		for(int i = 1; i <= min(m,siz[v]+siz[pos]); i++) r[i] = 0,c[i] = -3e12;
		for(int i = 1; i <= min(m,siz[pos]); i++){
			for(int j = 1; j <= min(m,siz[v]); j++){
				ll ff = f[pos][i] + f[v][j] + (g[v][j] > 0),gg = g[pos][i];
				if(i+j <= m && ff > r[i+j] || ff == r[i+j] && gg > c[i+j]){
					r[i+j] = ff, c[i+j] = gg;
				}
				ff = f[pos][i]+f[v][j],gg = g[pos][i] +g[v][j];
				if(i+j-1 <= m && ff > r[i+j-1] || ff == r[i+j-1] && gg > c[i+j-1]){
					r[i+j-1] = ff,c[i+j-1] = gg;
				}
			}
		}
		for(int i = 1;i <= min(m,siz[pos]+siz[v]); i++){
			f[pos][i] = r[i];
			g[pos][i] = c[i];
		}
		siz[pos] += siz[v];
	}
}
void solve(){
	cin >> n >> m;
	init();
	for(int i = 1;i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) a[i] = w[i] - b[i];
	for(int i = 1;i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout << f[1][m]+(g[1][m] > 0) << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
