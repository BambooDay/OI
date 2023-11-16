#include <bits/stdc++.h>
const int N = 4e5+10;

using namespace std;
bool v[N];
vector<int> e[N];
int n,m,q;
int s;
void dfs(int u){
	for(int to : e[u]){
		if(!v[to]){
			v[to] = 1;
			dfs(to);
		}
	}
}
int main(){
	cin >> n >> m >> q;
	for(int i = 1;i <= q; i++) {
		int u,v;
		cin >> u >> v;
		e[u].push_back(v+n);
		e[v+n].push_back(u);
	}
	for(int i = 1;i <= n+m; i++){
		if(!v[i]){
			s++;
			v[i] = 1;
			dfs(i);
		}
	}
	cout << s-1 << endl;
	return 0;
}
