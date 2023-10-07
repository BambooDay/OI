#include <bits/stdc++.h>

using namespace std;
int n, q;
int a[200];
int dp[200][200];
int main(){
	cin >> n >> q;
//	memset(dp,0x3f,sizeof dp);
	for(int i = 1;i <= q; i++){
		cin >> a[i];
//		dp[i][0] =dp[0][1]= 0;
	}
	a[0] = 0;
	a[q+1] = n+1;
	for(int i =1;i <= q; i++){
		dp[i][i] = a[i+1] - a[i-1] -2;
//		dp[i][0] = 0;
//		dp[i][i-1] = 0;
	}
	for(int len = 2; len <= q; len++){
		for(int l = 1; l <= q; l++){
			#define r l+len-1
			if(r > q)break;
			dp[l][r] = 1e9;
			for(int k = l; k <= r; k++){
				dp[l][r] = min(dp[l][r],dp[l][k-1]+dp[k+1][r] + a[r+1]-a[l-1]-2);
			}
		}
	}
	cout << dp[1][q];
	return 0;
}
