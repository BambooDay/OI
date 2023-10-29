#include <bits/stdc++.h>
#define int long long
using namespace std;
bool get(int x){
	for(int i = 2;i*i <= x; i++){
		if(x % i==0) return 0;
	} 
	return 1;
}
int n,k;

void solve(){
	cin >> n >> k;
	int ans = 0;
	int res = (k-1)*(k-1)*n;
	
	while(n){
		for(int i = n; i >= 1; i--){
			if(get(i)){
				ans += (i-k)*(i-k);
				n -= i;
				res = max(res,ans+(k-1)*(k-1)*n);
				break;
			}
		}
	}
	cout << res << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
