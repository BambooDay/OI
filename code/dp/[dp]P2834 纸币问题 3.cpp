#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
int n, a[N],w;
ll dp[N][M];

int main(){
	cin >> n >> w;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		dp[i][0] = 1;
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= w; j++){
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			if(j >= a[i]){
				dp[i][j] = max(dp[i-1][j] + dp[i][j - a[i]], dp[i][j]);
			}
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][w];
	return 0;
}
