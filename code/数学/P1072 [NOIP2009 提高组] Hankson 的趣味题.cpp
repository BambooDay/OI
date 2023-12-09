#include <bits/stdc++.h>

using namespace std;
int a0,a1,b0,b1;
void solve(){
	cin >> a0 >> a1 >> b0 >> b1;
	int p = a0/a1,q = b1/b0,ans = 0;
	for(int x = 1; x*x <= b1; x++){
		if(b1%x) continue;
		if(x%a1 == 0 && __gcd(x/a1,p)==1 && __gcd(b1/x,q) == 1) ans++;
		int y = b1/x;
		if(x == y) continue;
		if(y%a1 == 0 && __gcd(y/a1,p)==1 && __gcd(b1/y,q) == 1) ans++;
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
