#include <bits/stdc++.h>

using namespace std;
int s, n, m;
int v[200][200];
int dp[200][20004];
int main(){
	cin >> s >> n >> m;
	for(int i = 1; i <= s; i++){
		for(int j = 1;j <= n; j++){
			cin >> v[j][i];
			v[j][i] *= 2;
			v[j][i]++;
		}
	}
	for(int i = 1; i <= n; i++)
		sort(v[i]+1,v[i]+1+s);
//	memset(dp,-1,sizeof(dp));
//	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			for(int k = 1;k <= s; k++){
				if(j >= v[i][k]){
					dp[i][j] = max(dp[i][j],dp[i-1][j-v[i][k]] + i*k);
//					f[i][j] = max(f[i][j],f[i-1][j-v[i][k]]+w[i][k]);
				}
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
