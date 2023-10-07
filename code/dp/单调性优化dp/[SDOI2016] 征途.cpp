#include <bits/stdc++.h>

using namespace std;
int n;
int a[4000];
int sum[4000];
int m;
int dp[4000][4000];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	memset(dp,0x3f,sizeof dp);

	dp[0][0] = 0;
//	cout << dp[1] << endl;
	int now = 1;
	for(int len = 1; len <= m; len++){
		int now = 0;
		for(int i = 1;i <= n; i++){
			for(int j = now; j < i; j++){
				int x = dp[j][len-1] + (sum[i] - sum[j])*(sum[i] - sum[j]);
				if(dp[i][len] >= x){
					dp[i][len] = x;
					now = j;
				}
			}
		}
	}
	cout << dp[n][m] * m - sum[n]*sum[n];
	return 0;
}
