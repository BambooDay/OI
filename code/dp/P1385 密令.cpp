#include <bits/stdc++.h>
const int mod = 1e9+7;
#define int long long
using namespace std;
int dp[105][3000];

signed main(){
	for(int i = 0; i <= 25; i++){
		dp[1][i] =1;
	}	
	for(int i = 2;i <= 100; i++){
		dp[i][0] =1;
		for(int j = 1; j <= 2500; j++){
			for(int k = 0; k < 26; k++){
				if(j-k >= 0){
					dp[i][j] = (dp[i][j]+dp[i-1][j-k]) % mod;
				}
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int sum = 0;
		for(int i = 0; i < s.size(); i++) sum += s[i]-'a';
		cout << dp[s.size()][sum] % mod-1 << endl;
	}
	return 0;
}
