#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
vector<int> e[N];
int n,op;
vector<int> ans;
int dep[N];
bool f[N];
bool dfs(int pos, int fa){
	f[pos] = 0;
	dep[pos] = dep[fa]+1;
	if(e[pos].size() == 1 && fa){
		return f[pos] = (dep[pos]%2 == 0);
	} 
	if(e[pos].size() > 2 &&dep[pos]%2 == 0){
		f[pos] = 1;
		for(int to : e[pos]){
			if(to == fa) continue;
			 f[pos] &= dfs(to,pos);
		}
	}else{	
		for(int to : e[pos]){
			if(to == fa) continue;
			 f[pos] |= dfs(to,pos);
		}
	}
	return f[pos];
}

int dfs2(int pos, int fa){
	int res = 0;
	for(int to : e[pos]){
		if(to == fa || f[to] == 0) continue;
		res += dfs2(to,pos);
	}
	return max(1,res);
}
int res[N];
int main(){
	freopen("treegame.in","r",stdin);
	freopen("treegame.out","w",stdout);
	cin >> n >> op;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1;i <= n; i++){
		if(dfs(i,0)){
			ans.push_back(i);
			if(op == 2){
				res[i] = dfs2(i,0);
			}
		} 
	}
	sort(ans.begin(),ans.end());
	for(int i : ans){
		if(op == 1) cout << i << " ";
		else cout << res[i] << " ";
	}
	return 0;
}