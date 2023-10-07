#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;

using namespace std;
int n, m;
int ksm(int a, int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans  = ans * a % mod;
		}
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
} 
signed main(){
	cin >> n >> m;
	cout << ksm(2*(n+1),m) * (n+1-m) % mod * ksm(n+1,mod-2) % mod;	
	return 0;
}
