#include <bits/stdc++.h>
#define int __int128
const int N = 60;

using namespace std;
int dp[N][N][N];
signed n,a,b;
int ans = 0;
void write(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
signed main(){
	cin >> n >> a >> b;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= a; j++){
			for(int k = 0; k <= b; k++){
				for(int l = 0; l <= j; l++){
					for(int r = 0; r <= k; r++){
						dp[i][j][k] += dp[i-1][j-l][k-r];
					}
				}
			}
		}
	}
	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			ans += dp[n][i][j];
		}
	}
	write(ans);
	return 0;
}
