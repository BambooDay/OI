#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int  n, m, ans;
int fa[N<<2];
int find(int x){
	return fa[x] == x? x : fa[x] = find(fa[x]);
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n*3; i++) fa[i] = i;
	while(m--){
		int op,u,v;
		cin >> op >> u >> v;
		if(u > n || v > n){
			ans++;
			continue;
		}
		if(op ==1){
			if(find(u+n) == find(v) || find(u) == find(v + n)) ans++;
			else{
				fa[find(u)] = find(v);
				fa[find(u+n)] = find(v+n);
				fa[find(u+2*n)] = find(v + 2*n);
			}
		}else{
			if(find(u) == find(v) || find(u) == find(v + n)) ans++;
			else{
				fa[find(u+n)] = find(v);
				fa[find(u+n*2)] = find(v+n);
				fa[find(u)]  = find(v+n*2);
			}
		}
	}	
	cout << ans;
	return 0;
}
