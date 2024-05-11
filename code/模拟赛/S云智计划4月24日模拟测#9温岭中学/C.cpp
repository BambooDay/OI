#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int mod = 147744151;

using namespace std;
int n;
int _0 ,_1;
int k;
int ans;
void init(){
	cin >> n >> k;
	ans = _0 = _1 = 0;
}
void solve(){
	init();
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x&1) _1++;
		else _0++;
	}
	if(k == 0){
		if(_1 && _0){
			puts("0");
			return;
		}
		ans = 1;
		for(int i = 1; i <= n; i++){
			ans = ans*i%mod;
		}
		cout << ans << "\n";
		return;
	}
	if(abs(_1-_0) > 1){
		puts("0");
		return;
	}
	ans = 1;
	for(int i = 1; i <= _1; i++){
		ans = ans*i%mod;
	}
	for(int i = 1; i <= _0; i++){
		ans = ans*i%mod;
	}
	if(n%2 == 0) ans = ans*2%mod;
	cout << ans << "\n";
}
signed main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve(); 	
	return 0;
}
