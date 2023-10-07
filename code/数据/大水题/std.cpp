#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n,k,m;
set<int> e[N];
set<int> leaf;

void solve(){
//	cout << n << " " << m << " " << k << endl;
	for(int i = 1;i <= n; i++) e[i].clear();
	leaf.clear();
	for(int i =1;i <= m; i++){
		int u,v;
		cin >> u >> v;
		e[u].insert(v);
		e[v].insert(u); 
	}
	for(int i = 1; i <= n; i++){
		if(e[i].size() == 1) leaf.insert(i);
	}
	int cnt = 0;
	while(leaf.size() >= k){
		vector<int> nw;
		for(int i = 1 ;i <= k; i++){
			if(leaf.size() == 0){
				cout << cnt << endl;
				return;
			}
			int v = *leaf.begin();
			leaf.erase(v);
			int fa = *e[v].begin();
			e[fa].erase(v);
			e[v].erase(fa);
			if(leaf.count(fa)) leaf.erase(fa);
			if(e[fa].size() == 1){
				nw.push_back(fa);
			} 
//			cout << v << " ";
 		}
// 		cout << endl;
		for(int fa : nw){
			leaf.insert(fa);
		}
		cnt++;
	}
	cout << cnt << endl;
}
int main(){
//	freopen("dst.in","r",stdin);
//	freopen("dst.ans","w",stdout);
	while(cin >> n >> m >> k && n) solve();
	return 0;
}
