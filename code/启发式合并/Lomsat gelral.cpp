#include <bits/stdc++.h>
const int N = 1e5+10;
#define ll long long
using namespace std;
int n,c[N],id[N],tot = 0;
struct Node{
	int mx_cnt = 0;
	ll mx_sum = 0;
	map<int,int> cnt;
	vector<int> v;
	void add(int u){
		cnt[c[u]]++;
		if(cnt[c[u]] > mx_cnt) mx_cnt = cnt[c[u]],mx_sum = c[u];
		else if(cnt[c[u]] == mx_cnt) mx_sum += c[u];
		v.push_back(u);
	}	
	int size(){
		return v.size();
	}
}sub[N]; 
ll ans[N];
vector<int> e[N];
void dfs(int u, int fa){
	id[u] = ++tot;
	int mx_son = -1,mx_siz = 0;
	for(int v : e[u]){
		if(v == fa) continue;
		dfs(v,u);
		if(sub[id[v]].size() > mx_siz){
			mx_siz = sub[id[v]].size();
			mx_son = v;
		}
	} 
	if(mx_son != -1) id[u] = id[mx_son];
	for(int v : e[u]){
		if(v == fa || v == mx_son) continue;
		for(int son : sub[id[v]].v){
			sub[id[u]].add(son);
		}
	}
	sub[id[u]].add(u);
	ans[u] = sub[id[u]].mx_sum;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i =1;i< n; i++){
		int  u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u); 
	}
	dfs(1,0);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
