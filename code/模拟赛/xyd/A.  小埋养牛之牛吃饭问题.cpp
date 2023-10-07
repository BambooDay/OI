#include <bits/stdc++.h>
#define ll long long 
const int N = 1e6+10;
const int M = 1e4+10;

using namespace std;
int k,n,m;
vector<int> e[1005];
int sum[1005];
int a[200];
bool v[1005];
void dfs(int s){
	v[s] = 1;
	for(auto to : e[s]){
		if(v[to]) continue;
		sum[to]++;
		dfs(to);
	}
}
int main(){
	cin >> k >> n >> m;
	for(int i = 1;i <= k; i++){
		cin >> a[i];
		sum[a[i]]++;
	}
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	} 
	for(int i =1;i <= k; i++){
		memset(v,0,sizeof v);
		dfs(a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(sum[i] == k) ans++;
	}
	cout << ans;
	return 0;
}
/*
2 4 4
2
3
1 2
1 4
2 3
3 4
*/
