#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
vector<int> g[N];
int n,m,ans = 0;
int col[N],now[N];
void merge(int x, int y){
	for(int i : g[x]){
		if(col[i-1] == y) ans--;
		if(col[i+1] == y) ans--;
	}
	for(int i : g[x]) col[i] = y;
	for(int i : g[x]) g[y].push_back(i);
	g[x].clear();
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> col[i];
		now[col[i]] = col[i];
		if(col[i] != col[i-1]) ans++;
		g[col[i]].push_back(i);
	}	
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x,y;
			cin >> x >> y;
			if(x == y) continue;
			if(g[now[x]].size() >  g[now[y]].size()) swap(now[x],now[y]);
			merge(now[x],now[y]);
		}else cout << ans << endl;
	}
	return 0;
}
