#include <bits/stdc++.h>
#define int unsigned long long
const int N = 1e6+10;
const int BASE = 13331;

using namespace std;
int hs[N];
int base[N];

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	s = " "+ s;
	fill(hs,hs+9+n,0);
	for(int i = 1; i <= n; i++){
		hs[i] = hs[i-1] * BASE + s[i]; 
	}
	int ll,lr,rl,rr;
	ll = lr = 1,rl = rr = n;
	int ans = 0;
	while(ll < rl){
		int x = hs[lr] - hs[ll-1]*base[lr-ll+1];
		int y = hs[rr] - hs[rl-1]*base[rr-rl+1];
		if(x == y){
			ans++;
			ll = lr = lr+1;
			rr = rl = rl-1;
			continue;
		}
		lr++;
		rl--;
	}
	ans *= 2;
	if(n % 2) ans++;
	else{
		if(ll != lr) ans++;
	}
	cout << ans << endl;
}
signed main(){

	base[0] = 1;
	for(int i = 1; i <= 1e6; i++){
		base[i] = base[i-1] * BASE; 
	}
	int T;
	cin >> T;
	while(T--) solve();	
	return 0;
} 
