#include <bits/stdc++.h>

using namespace std;
int n, m, k ,c;
int a[200],b[200];
int w[200],v[200];
int dp[150][150][20020];

int main(){
	cin >> n >> m >> k >> c;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i =1;i <= n; i++) {
		cin >> b[i];
	}
	for(int i =1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		w[i] = a[x]*a[y];
		v[i] = b[x]+b[y];
		dp[1][i][v[i]] = w[i];
	}
	int ans = -1;
	for(int t = 1;t <= k; t++){
		for(int i = t; i <= m; i++){
			for(int j = 20*m; j >= 0; j-- ){
				dp[t][i][j] = max(dp[t][i-1][j],dp[t][i][j]);
				if(v[i] <= j){
					if(dp[t-1][i-1][j-v[i]] > 0)
						dp[t][i][j] = max(dp[t][i][j],dp[t-1][i-1][j-v[i]]+w[i]); 
				}
				if(j >= c){
					ans = max(ans,dp[t][i][j]);
				}
				
			}
		}
	}
	if(ans > 0)
		cout << ans;
	else cout << -1;
	return 0;
}
