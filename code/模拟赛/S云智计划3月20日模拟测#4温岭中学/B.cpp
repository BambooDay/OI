#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int mod = 1e9+7;

using namespace std;
int c[N];
int inv(int x){
	if(x == 0) return 1;
	int ans = 1,b = mod-2;
	while(b){
		if(b&1) ans = ans*x%mod;
		b>>=1;
		x = x*x%mod;
	}
	return ans;
}
int C(int n, int m){
//	if(n < m){
//		cout << n << " " << m << endl;
//	}
	return c[n]*inv(c[m])%mod*inv(c[n-m])%mod;
}
int n;
int a[N];
signed main(){
	freopen("paper.in","r",stdin);
	freopen("paper.out","w",stdout);
	cin >> n;
	c[0] = 1;
	for(int i = 1;i <= N-1; i++) c[i] = c[i-1]*i%mod;
	int ans = 0;
//	for(int i = 1;i <= n+3; i++){
//		for(int j = 1; j <= n+1-i+3; j++){
//			cout << C(i-1+j-1,i-1) << " "; 
//		}
//		cout << endl;
//	}
	for(int i = 1; i <= n+1; i++){
		cin >> a[i];
	}
	for(int i =1;i <= n+1; i++){
//		if(a[i] != a[i+1]){
//		cout << a[i]+i-1 << " "<< i << endl;
		ans = (ans+C(a[i]+i-1,i))%mod; 	
//		}
	}
	cout << ans;
	return 0;
} 
