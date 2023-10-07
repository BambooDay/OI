#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, n;
void solve(){
	cin >> a >> n;
	while(n % 2 == 0) n /= 2;
	for(int i = 3;i * i <= n; i++){
		if(n % i == 0){
			if(a % i){
				cout << "No" << endl;
				return;
			}
		}
		while(n % i == 0) n /= i;
	}
	if(n > 1){
		if(a % n){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
