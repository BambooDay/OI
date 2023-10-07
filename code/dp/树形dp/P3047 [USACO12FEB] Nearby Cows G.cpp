#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
int n;
int f[N][25],d[N][25];
int val[N];
int k;
vector<int> e[N];
void dfs1(int pos, int fa){
	for(int i = 0; i <= k; i++){
		f[pos][i] = val[pos];
	}
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs1(to,pos);
		for(int i = 1; i <= k; i++){
			f[pos][i] += f[to][i-1];
		}
	}
}
void dfs2(int pos, int fa){
	for(int to : e[pos]){
		if(to == fa) continue;
		d[to][1] += f[pos][0];
		for(int i = 2;i <= k; i++){
			d[to][i] += d[pos][i-1] - f[to][i-2];
		} 
		dfs2(to,pos);
	} 
}
signed main(){
	cin >> n >> k;
	for(int i =1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	for(int i = 1;i <= n; i++) cin >> val[i];
	dfs1(1,0);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			d[i][j] = f[i][j];
		}
	}
	dfs2(1,0);
	for(int i = 1;i <= n; i++){
		cout << d[i][k] << endl;
	}
	return 0;
}
