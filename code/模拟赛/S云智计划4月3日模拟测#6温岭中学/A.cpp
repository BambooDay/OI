#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;

using namespace std;
int n,m;
int s = 0;
int sm;
int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
signed main(){
	cin >> n >> m;
	sm = (1+m)*m/2ll%mod;
//	cout << sm << endl;
	for(int i = 1; i <= m; i++){
		if(i&1){
			s = (s+(sm+m*i%mod-m/2ll)%mod+mod)%mod;
		}else{
			
			s = (s+(sm+m*i%mod-(m+1)/2ll)%mod+mod)%mod;
		}
//		if(s < 0) cout << s << endl;
	}	
	int pw = ksm(m,n-2);
//	cout << 998244353-214646272 << endl;
	cout << n*(n-1)/4ll*pw%mod*s%mod << endl;
	return 0;
}
