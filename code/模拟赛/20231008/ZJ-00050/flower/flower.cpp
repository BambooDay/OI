#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[3005];
long long dp[3005][3005];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
//	memset(dp,0x3f,sizeof dp);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 1e18;
		}
	}
	dp[1][1] = abs(a[1] - 1);
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= min(i,m);j++){
			dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + abs(a[i] - j);
		}
	}	
	long long ans = 1e18;
	for(int i = 1; i<= m; i++) ans = min(ans,dp[n][i]);
	cout << ans << endl;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
