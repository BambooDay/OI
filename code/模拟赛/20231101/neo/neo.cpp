#include <bits/stdc++.h>
const int N = 5e5+10;
const int mod = 998244353;
using namespace std;
vector<int> e[N];
int deg[N];
int n;
int res = 0;
int a[N];

bool check(){
	int d[1005];
	for(int i = 1;i <= n; i++) d[i] = deg[i];
	for(int i = 1;i <= n; i++){
		if(d[a[i]] > 1) return 0;
		for(int to : e[a[i]]){
			d[to]--;
		}
	}
	return 1;
}
bool vis[N];
void dfs(int dep){
	if(dep > n){
		if(check()){
			res++;
			//for(int i = 1; i <= n; i++) cout << a[i] << " ";
			//cout << endl;
		} 
		return;
	}
	for(int i = 1;i <= n; i++){
		if(!vis[i]){
			vis[i] = 1;
			a[dep] = i;
			dfs(dep+1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("neo.in","r",stdin);
	freopen("neo.out","w",stdout);
	cin >> n;
	for(int i = 1;i < n; i++){
		int u,v;
		cin >> u >> v;
		deg[u]++,deg[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int cnt = 0;
	bool f = 1;
	for(int i = 1;i <= n; i++){
		if(deg[i] > 2){f = 0;break;}
		if(deg[i] <= 1) cnt++;
		if(cnt > 2) f = 0;
	}
	if(!f){
		dfs(1);
		cout << res << endl;
	}else{
		int ans = 1;
		for(int i = 2; i <= n;i++){
			ans = ans * 2 % mod;
		}
		cout << ans << endl;
	}
	return 0;
}