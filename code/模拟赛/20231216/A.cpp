#include <bits/stdc++.h>
const int N = 305;

using namespace std;
int dp[N][N][N];
int n,m;
string s,t;
int ans = 0;
int main(){
	freopen("master.in","r",stdin);
	freopen("master.out","w",stdout);
	cin >> n >> m;
	cin >> s >> t;
	s = " " + s;
	t = " " + t;
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= n; j++){
			if(s[i] == t[j]){
				dp[i][j][0] = dp[i-1][j-1][0]+1;
			}
//				cout << dp[i][j][k] << endl; 
			ans = max(ans,dp[i][j][0]);			
			for(int k = 1; k <= m; k++){
				if(s[i] == t[j]){
					dp[i][j][k] = dp[i-1][j-1][k]+1;
				}else{
					dp[i][j][k] = dp[i-1][j-1][k-1]+1;
				}
//				cout << dp[i][j][k] << endl; 
				ans = max(ans,dp[i][j][k]);
			}
		}
	}		
	cout << ans;
	return 0;
}
