#include<bits/stdc++.h>

using namespace std;
int dp[105][20005];
int n,m,s;
int a[105][105];

int main(){
	cin >> s >> n >> m;
	for(int i = 1; i<= s; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[j][i];
		}
	}	
	for(int i = 1;i <= n; i++){
		sort(a[i]+1,a[i]+1+s);
	}
//	memset(dp,-1,sizeof dp);
//	dp[0][0] = 0;
//	for(int i = 1; i <= m; i++) dp[0][i] = 0;
	for(int i = 1; i <= n; i++){
//		dp[i][0] = dp[i-1][0];
		for(int j = 1; j<= m; j++){
			dp[i][j] = dp[i-1][j];
			for(int k = 1;k <= s&&a[i][k]*2 < j; k++){
				dp[i][j] = max(dp[i][j],dp[i-1][j-a[i][k]*2-1]+i*k);
//				cout << i << " " << j << " " << k << " " << dp[i][j] << endl;
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
