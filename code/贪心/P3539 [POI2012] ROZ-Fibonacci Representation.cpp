#include <bits/stdc++.h>
#define int long long

using namespace std;
int n,t,m = 2;
int f[1005];
void solve(){
	cin >> n;
	int res = 0;
	while(n){
		res++;
		int now = upper_bound(f+1,f+1+m,n) - f;
		n = min(f[now] - n, n - f[now-1]);
	}
	cout << res << endl;
}
signed main(){
	cin >> t;
	f[1] = 1,f[2] = 2;
	while(f[m] <= 4e17){
		m++;
		f[m] = f[m-1] + f[m-2];
	}	
	while(t--){
		solve();
	}	
	return 0;
} 
