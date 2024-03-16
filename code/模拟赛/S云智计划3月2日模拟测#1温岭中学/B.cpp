	#include <bits/stdc++.h>
	const int N = 1005;
	
	using namespace std;
	string s,t;
	int dp[N][N],ne[1000006][30],now[30];
	int n,m;
	int main() {
		freopen("vlcs.in","r",stdin);
		freopen("vlcs.out","w",stdout);
		cin >> s >> t;
		n = s.size();
		m = t.size();
		s = " " + s;
		t = " " + t;
		for(int i = 0; i < 26; i++) now[i] = n+1;
		for(int i = n; i >= 0; i--) {
			for(int j = 0; j < 26; j++) ne[i][j]=now[j];
			now[s[i]-'a'] = i;
		}
		for(int i = 0; i <= m; i++){
			for(int j = 0; j <= m; j++){
				dp[i][j] = n+1;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j <= i; j++){
				if(dp[i][j] != n+1){
					dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
					dp[i+1][j+1] = min(dp[i+1][j+1],ne[dp[i][j]][t[i+1]-'a']);
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; i++){
			if(dp[m][i] != n+1){
				ans = i;
			}
		}
		cout << ans;
		return 0;
	}

