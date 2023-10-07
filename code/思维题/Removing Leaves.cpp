#include <bits/stdc++.h>
const int N = 2e5+10;
using namespace std;
set<int> g[N],leaf[N];
int n,k;
struct cmp{
	bool operator()(const int x, const int y) const{
		return (leaf[x].size() == leaf[y].size()) ? x < y : leaf[x].size() > leaf[y].size();
	}
};

void solve(){
	cin >> n >> k;
	for(int i = 0; i <= n; i++){
		g[i].clear();
		leaf[i].clear();
	}
	int ans = 0;
	for(int i = 1;i < n; i++){
		int u,v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 0; i <= n; i++){
		if(g[i].size() == 1){
			leaf[*g[i].begin()].insert(i);
		}
	}
	set<int,cmp> s;
	for(int i =1;i <=  n; i++) s.insert(i);
	while(1){
		int u = *s.begin();
		if(leaf[u].size() < k) break;
		for(int i = 0; i < k; i++){
			int v = *leaf[u].begin();
			g[v].erase(u);
			g[u].erase(v);
			s.erase(u);
			s.erase(v);
			leaf[u].erase(v);
			if(leaf[v].count(u)) leaf[v].erase(u);
			if(g[u].size() == 1){
				int w = *g[u].begin();
				s.erase(w);
				leaf[w].insert(u);
				s.insert(w);
			}
			s.insert(u);
		}
		ans++;
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
