#include <bits/stdc++.h>
#define int long long
const int N = 1e6+10;
const int mod = 998244353;

using namespace std;
int a[N];
int n,m;
int ans = 0;
signed main(){
	freopen("over.in","r",stdin);
	freopen("over.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		char ch;
		//for(int j = 1; j <= m-30; j++) cin >> ch;	
		for(int j = 1; j <= m; j++){
			cin >> ch;
			a[i] = (a[i]<<1) + ch-'0';
			//a[i] %= mod;
		}
		//cout<< a[i] << " ";
	}
	//cout << endl;
	for(int i = 1;i <= n; i++){
		for(int j = i; j <= n; j++){
			ans = (ans + (a[i]^a[j])%mod*(a[i]^a[j])%mod) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}