#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int a[N];
int dp[N];
vector<int>e[N];
void dfs1(int pos, int fa){
	dp[pos] = a[pos] ? 1 : -1;
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs1(to,pos);
		dp[pos] += max(dp[to],0);
	}
} 
void dfs2(int pos, int fa){
	dp[pos] += max(0,dp[fa] - max(0,dp[pos]));
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs2(to,pos);
	}
}
int n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1;i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i = 1; i <= n; i++) cout << dp[i] << " ";
	return 0;
}
