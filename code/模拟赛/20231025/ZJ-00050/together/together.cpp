#include <bits/stdc++.h>
#define int long long
const int N = 2e6+10;
const int mod = 998244353;
using namespace std;
int n,m;
int a[N];
signed main(){
	freopen("together.in","r",stdin);
	freopen("together.out","w",stdout);
	//int cnt = 1;
	//for(int i = 1; i <= 30; i++) cnt = cnt*10%mod;
	///cout << cnt << endl;
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i];
	int ans = 1;
	int i = 30;
	while(i--){
		if(m & 1){
			ans = (ans * (n*(n-1)/2ll% mod*(n-2)/ 3ll % mod) % mod);
		}else{
			ans = (ans * (n*(n-1)/2ll%mod)%mod);
		}
		m>>=1;
	}
	cout << ans << endl;
	return 0;
}