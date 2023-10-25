#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int ans = 0;
int a,b,c;
bool dfs(int la, int lb, int rstb, int rstc){
	la *= a,lb*=b;
	if(la >= rstb || lb >= rstc){
		if(rstb == rstc) return 1;
		return 0;
	}
	bool f = 0;
	for(int i = 0; la*i <= rstb && lb*i <= rstc; i++){
		f |= dfs(la,lb,rstb-la*i,rstc-lb*i);
		if(f) return 1;
	}
	return 0;
}
void solve(){
	cin >> a >> b >> c;
	if(a == b && b == c){
		cout << ((a==1)?-1:2) << endl;
		return;
	}
	if(b == c){
		cout << 1 << endl;
		return;
	}
	if(a == b ){
		cout << 0 << endl;
		return;
	}
	if(b < a || c < b||c<a){
		cout << 0 << endl;
		return;
	}
	cout << dfs(1,1,b,c) << endl;
}
signed main(){
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}