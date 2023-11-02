#include <bits/stdc++.h>

using namespace std;
int n,k,a[105],ans;
int pos[105],ne[105];
int bk[105],id,vis[105];

int main(){
	cin >> n >> k;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1;i <= n; i++) pos[i] = n+1;
	for(int i = n; i ; i--){
		ne[i] = pos[a[i]];
		pos[a[i]] = i;
	}	
	for(int i = 1;i <= n; i++){
		if(vis[a[i]]){
			bk[vis[a[i]]] = i;
			continue;
		}
		if(id < k) bk[++id] = i,vis[a[i]] = id;
		else{
			int ma = 0,p = 0;
			for(int j = 1; j <= id; j++){
				if(ne[bk[j]] > ma) ma = ne[bk[j]],p = j;
			}
			vis[a[bk[p]]] = 0;
			bk[p] = i;
			vis[a[i]] = p;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
