#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
int d[50],b[50],a[50];
int n;
void solve(){
	memset(b,0,sizeof b);
	cin >> n;
	for(int i =1; i <= 41; i++){
		if(n < d[i]) break;
		b[i] = n / d[i];
//		cout << b[i] << " ";
	}
//	cout << endl;
	for(int i = 1; i <= 41; i++){
		if(n < d[i]) break;
		a[i] = b[i] - b[i+1];
	}
	int ans = 0;
	for(int i =1;i <= 41; i++){
		if(d[i] > n) break;
		ans = (ans + a[i]*(i+1) % mod) % mod;
	}
//	if(ans == 0) exit(n);
	cout << ans << endl;
}

signed main(){
	d[0] = 1;
	for(int i =1;i <= 41; i++){
		d[i] = d[i-1]*i / __gcd(d[i-1],i);
	}
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
