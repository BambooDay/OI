#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n,m;
vector<int> e[N];
int vma[N],vmi[N];
int deg[N];
int ans = -2e9;

int main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> vma[i];
		vmi[i] = 2e9;
	}
	for(int i = 1 ;i <= m; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		deg[v]++;
	}
	queue<int> q;
	for(int i = 1;i <= n; i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans = max(ans,vma[u]-vmi[u]);
		vmi[u] = min(vmi[u],vma[u]); 
		for(int v : e[u]){
//			vma[v] = max(vma[v],vma[u]);
			vmi[v] = min(vmi[v],vmi[u]);
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	} 
	cout << ans;
	return 0;
}
