#include <bits/stdc++.h>
const int N = 1001;

using namespace std;
vector<pair<int,int> > e[N];
int n,m,k;
int ans[1000006],tot;
void dfs(int pos, int rest, int en){
	if(rest < 0) return;
	if(pos == en){
		//cout << rest << " ";
		ans[++tot] = rest;
		return;
	}
	for(auto to : e[pos]){
		dfs(to.first,rest - to.second,en);
	}
}
int t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m >> k >> t;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		//e[v].push_back({u,w});
	}
	while(t--){
		int st;
		cin >> st;
		tot = 0;
		dfs(1,k,st);
		sort(ans+1,ans+1+tot);
		tot = unique(ans+1,ans+1+tot)-ans-1;
		
		cout << tot << endl;
	}
	return 0;
}