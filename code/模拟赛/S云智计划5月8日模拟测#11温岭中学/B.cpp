#include <bits/stdc++.h>
const int N = 2e5+10;
#define int long long
const int mod = 1e9+7;

using namespace std;
int n;
int a[N];
int ans = 0;
int jc[N],pw[N];
int ksm(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res%mod;
}
int C(int x,int y){
//	if(!y) return 0;
	return jc[x]*ksm(jc[y],mod-2)%mod*ksm(jc[x-y],mod-2)%mod;   //jc[x]/jc[y]/jc[x-y]
}
signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	jc[0] = 1;
	pw[0] = 1;
	for(int i = 1; i <= N-10; i++) jc[i] = jc[i-1]*i%mod,pw[i] = pw[i-1]*2%mod;
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	sort(a+1,a+1+n);
//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
//	pw[0] = 0;
	for(int i = 1;i <= n; i++){
		if(a[i] > i) continue;
		// ans += C(i-1,i-a[i])+2^(n-i)
//		cout << i-1 << " " << i-a[i] << " " << C(i-1,i-a[i]) << " " << pw[n-i] << endl;
		ans = (ans+C(i-1,i-a[i])*pw[n-i]%mod)%mod;
//		if(ans < 0) cout << "xxx" << endl;
//		cout << i << " " << a[i]  << " " << ans << endl;
	}
	cout << ans;
	return 0;
}
