#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;
int n,f[300][300],dp[2][300][300];
int ans = INF;

signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout); 
	double st = clock();
	cin >> n;
	for(int i =1;i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> f[i][j];
			if(i == j) continue;
			if(f[i][j] == 0) f[i][j] = INF;
		}
	}	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i<= n; i++){
			if(i== k) continue;
			for(int j = 1; j <= n; j++){
				if(j == k || j == i) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	} 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[0][j][i] = f[i][1] + f[1][j];
			dp[1][j][i] = f[i][n] + f[n][j];
		}
	} 
	for(int k = 1; k <= n; k++){
		for(int l = 1; l <= n; l++){
			for(int i =1;i <= n; i++){
				for(int j = 1; j <= n; j++){
					dp[0][j][i] = min(dp[0][j][i], dp[0][k][l] + f[i][k] + f[k][l] + f[l][j]);
					dp[1][j][i] = min(dp[1][j][i], dp[1][k][l] + f[i][k] + f[k][l] + f[l][j]); 
				} 
			}
		}
	} 
	for(int i = 1; i <= n; i++){
		for(int  j = 1; j <= n; j++){
			ans = min(ans, dp[0][j][i] + f[j][i] + dp[1][i][j]) ;
		}
	}
	cout << ans;
	return 0;
}
