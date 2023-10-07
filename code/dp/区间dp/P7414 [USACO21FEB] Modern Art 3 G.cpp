#include <bits/stdc++.h>

using namespace std;
int n;
int a[400];
int dp[400][400];

int main(){
	cin >> n;
	memset(dp,0x3f,sizeof dp);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]) dp[i][i] =1;
	}	
	for(int len = 2; len <= n; len++){
		for(int l = 1;l <= n; l++){
			#define r (l+len-1)
			if(r > n) break;
			if(a[l] == a[r]) dp[l][r] = dp[l][r-1];
			else{
				for(int k = l; k < r; k++){
					dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]);
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
