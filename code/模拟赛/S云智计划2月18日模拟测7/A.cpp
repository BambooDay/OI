#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;

using namespace std;
string s;
int dp[N][12];
int n;

signed main(){
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1; i <= 10; i++){
		dp[1][i] = -1;
	}	
	dp[1][s[1]-'0'] = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < 10; j++){
			if(dp[i-1][j] == -1) continue;
			if(s[i]-'0'+j < 10) dp[i][s[i]-'0'+j] = max(dp[i][s[i]-'0'+j],dp[i-1][j]+1);
			else dp[i][s[i]-'0'+j-10+1] = max(dp[i][s[i]-'0'+j-10+1],dp[i-1][j]+2);
		} 
	}
	int ans = 0;
	for(int i = 0; i < 10; i++) ans = max(ans,dp[n][i]);
	cout << ans;
	return 0;
}
