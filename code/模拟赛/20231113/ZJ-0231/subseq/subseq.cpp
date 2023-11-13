#include <bits/stdc++.h>
const int N = 2e5+10;
const int mod = 998244353;
#define int long long
using namespace std;
int n;
int a[N];
int f[N];
int ans = 0;
void solve(){
	//cin >> n;
	scanf("%lld",&n);
	ans = 0;
	for(int i = 1; i <= n; i++){
		//cin >> a[i];
		scanf("%lld",&a[i]);
		f[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		int ma = 0;
		for(int j = i-1; j; j--){
			if(a[j] >= a[i]) continue;
			ma = max(ma,a[j]);
			if(a[j] == ma){
				f[i] = (f[i]+f[j]) % mod;
			}
		}
		f[i] = max(f[i],1ll);
	}
	int ma = 0;
	for(int i = n; i; i--){
		ma = max(ma,a[i]);
		if(ma == a[i]){
			ans = (ans + f[i]) % mod;
			//cout << a[i] << " ";
		} 
	}
	//cout << endl;
	printf("%lld\n",ans);
}
signed main(){
	freopen("subseq.in","r",stdin);
	freopen("subseq.out","w",stdout);
	int t;
	cin >> t;
	//solve();
	while(t--) solve();
	return 0;
}