#include<bits/stdc++.h>
#define mod 998244353
const int N = 5005;
using namespace std;
int n,dp[N][30][30],ans;
string s;
int main() {
	cin >> n >> s;
	s = " "+s;
	dp[0][26][26] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 26; j++){
			for(int k = 0; k <= 26; k++){
				if(dp[i-1][j][k]){
					for(int l = 0; l < 26; l++){
						if((s[i] == '?' || s[i] == l+'a') && l != j && l != k){
							dp[i][k][l] = (dp[i][k][l] + dp[i-1][j][k]) % mod;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(i == j) continue;
			ans = (ans + dp[n][i][j]) % mod;
		}
	}
	cout << ans;
	return 0;
}

