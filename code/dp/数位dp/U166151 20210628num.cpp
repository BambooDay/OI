#include <bits/stdc++.h>
#define int long long
const int mod = 999983;
using namespace std;
int n;
int s[20],cnt;
int ma = -1;
int dp[1005][10000];

signed main(){
	cin >>n;
	string s1;
	cin >> s1;
	for(int i =0 ;i < s1.size(); i++) {
		s[++cnt] = s1[i] - '0';
		ma = max(ma,s[cnt]);
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		int up = ma*i;
		for(int j = 0; j <= up; j++){
			for(int k = 1; k <= cnt; k++){
				if(j >= s[k]){
					dp[i][j] = (dp[i][j] + dp[i-1][j-s[k]]) % mod;
				}
			}
		}
	}	
	int ans = 0; 
	for(int i = 0; i <= ma * n;i++){
		ans = (ans + dp[n][i] * dp[n][i] % mod) % mod;
	}
	ans = (ans * 2) % mod;
	int m1 = (n >> 1);
	int m2 = n - m1;
	int ans1 = 0,ans2 = 0;
	for(int i = 0; i <= ma * m1; i++){
		ans1 = (ans1 + dp[m1][i]*dp[m1][i] % mod) % mod;
	}
	for(int i = 0; i <= ma * m2; i++){
		ans2 = (ans2 + dp[m2][i]*dp[m2][i] % mod) % mod;
	}
	cout << ((ans - ans1*ans2 % mod) % mod + mod)%mod;
	return 0;
}
