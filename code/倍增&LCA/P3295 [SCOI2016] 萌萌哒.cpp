#include <bits/stdc++.h>
const int N = 1e5+10;
const int mod = 1e9+7;
#define int long long
using namespace std;;
int fa[N][30];
int find(int x, int k){
	return fa[x][k] == x? x : fa[x][k] = find(fa[x][k],k);
}
bool vis[N];
int n,m;

signed main(){
	cin >> n >> m;
	for(int i = 0; (1<< i) <= n; i++){
		for(int j = 1; j + (1 << i) - 1 <= n; j++){
			fa[j][i] = j;
		}
	} 
	for(int i = 1;i <= m; i++){
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int idx = log2(r1-l1+1);
		int fl1 = find(l1,idx);
		int fl2 = find(l2,idx);
		fa[fl1][idx] = fl2;
		int fr1 = find(r1 - (1<<idx) + 1,idx);
		int fr2 = find(r2 - (1 << idx) + 1, idx);
		fa[fr1][idx] = fr2;
	}
	for(int idx = log2(n); idx >= 1; idx--){
		for(int i = 1; i + (1 << idx)-1 <= n; i++){
			int f = find(i,idx);
			if(f == i) continue;
			int fa1 = find(i,idx-1),fa2 = find(f,idx-1);
			fa[fa1][idx-1] = fa2;
			fa1 = find(i+(1<<(idx-1)),idx-1);
			fa2 = find(f+(1<<(idx-1)),idx-1);
			fa[fa1][idx-1] = fa2;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		int f = find(i,0);
		if(!vis[f]){
			cnt++;
			vis[f] = 1;
		}
	}
	int ans = 1,x = 10;
	cnt--;
//	cout << cnt << endl;
	while(cnt > 0){
		if(cnt & 1){
			ans = x*ans % mod;
		}
		x = x*x % mod;
		cnt >>= 1;
	}
	cout << ans * 9 % mod;
	return 0;
}
