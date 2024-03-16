#include <bits/stdc++.h>
#define int unsigned long long
const int N = 1e5+10;
const int BASE = 13331;

using namespace std;
string s;
int n;
int hs[N],sh[N],base[N];
int get_hs(int l, int r){
	return hs[r]-hs[l-1]*base[r-l+1];
}
int get_sh(int l, int r){
	return sh[l]-sh[r+1]*base[r-l+1];
}
void solve(){
	cin >> n;
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n; i++){
		hs[i] = hs[i-1]*BASE + s[i];
	}
	sh[n+1] = 0;
	for(int i = n; i; i--){
		sh[i] = sh[i+1]*BASE + s[i];
	}
	if(get_hs(1,n) != get_sh(1,n)){
		puts("1");
		return;
	}
	for(int i = 1;i < n; i++){
		if(get_hs(1,i) != get_sh(1,i) && get_hs(i+1,n) != get_sh(i+1,n)){
			puts("2");
			return;
		} 
	}
	puts("-1");
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	base[0] = 1;
	for(int i = 1;i <= 1e5; i++) base[i] = base[i-1]*BASE;
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
