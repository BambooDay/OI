#include <bits/stdc++.h>
const int N = 2e3+10;
const int M = 4e6+10;
const int mod = 998244353;

using namespace std;
int n,a[N][N],px[M],py[M];
int fa[N<<1],siz[N<<1],c[N<<1],cnt,vis[N<<1];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int L[N<<1],R[N<<1],idx;
vector<int> e[N<<1];
void merge(int x, int y){
	x = find(x),y = find(y);
	if(x == y){
		if((++c[x]) == siz[x]*(siz[x]-1) / 2) vis[x] = 1;
		return;
	}
	fa[x] = fa[y] = ++cnt;
	siz[cnt] = siz[x]+siz[y];
	c[cnt] = c[x]+c[y]+1;
	e[cnt].push_back(x);
	e[cnt].push_back(y);
	if(c[cnt] == (siz[cnt]*(siz[cnt]-1)/2)) vis[cnt] = 1;
}
int dp[N][N];
vector <int> seg[N<<1];
void dfs(int x){
	if(x <= n){
		L[x] = R[x] = ++idx;
		seg[idx].push_back(idx);
		return;
	}
	L[x] = n+1,R[x] = 0;
	for(int to : e[x]){
		dfs(to);
		L[x] = min(L[x],L[to]);
		R[x] = max(R[x],R[to]);
	}
	if(vis[x]) seg[R[x]].push_back(L[x]);
} 
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			cin >> a[i][j];
			px[a[i][j]] = i,py[a[i][j]] = j;
		}
	}
	for(int i = 1;i <= n; i++) siz[i] = 1,c[i] = 0,vis[i] = 1;
	for(int i = 1;i <= 2*n; i++) fa[i] = i;
	cnt = n;
	for(int i =1;i <= (n*(n-1) /2); i++) merge(px[i],py[i]);
	dp[0][0] = 1;
	dfs(cnt);
	for(int i =1;i <= n; i++){
		for(int j =1;j <= n; j++){
			for(int k : seg[i]){
				dp[i][j] = (dp[i][j] + dp[k-1][j-1]) % mod;
			}
		}
	}
	for(int i =1;i <= n; i++) cout << dp[n][i] << " ";
	return 0;
}
