#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
const int N  = 1e6+10;
using namespace std;
int n; 
int dp[2][N];
int l[505],r[505];
int a[2005],tot = 0;
int sum[N];
map<int,int> m;
signed main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin >> n;
	int ma = 0;
	a[++tot] = 0;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		ma = max(ma,r[i]);
	}

	for(int i = 0; i <= ma; i++){
		sum[i] = 1;
	}
	int v = 1;
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = l[i]; j <= r[i]; j++){
			dp[v][j] = sum[j-1];
		}
		for(int j = 1; j <= ma; j++){
			dp[v^1][j] = 0; 
			cnt = (cnt+dp[v][j]%mod)%mod;
			sum[j] = (cnt+sum[j])%mod;
		}
		//cout << sum[99] << " xxx " << endl;
		v ^= 1;
		/*
		cout << i << ": " << endl;
		for(int j = 1; j <= 4; j++){
			cout << dp[v^1][j] << " ";
		}
		cout << endl;
		for(int j = 1; j <= 4; j++){
			cout << sum[j] << " xxx ";
		}
		cout << endl;

3
1 100
1 100
1 100
176850
		*/
	}

	cout << (sum[ma]-1)%mod<< endl;
	return 0;
}