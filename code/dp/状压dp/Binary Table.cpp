#include <bits/stdc++.h>

using namespace std;

string st;
int n,m;
int num[100005];
int dp[30][(1<<20)+10];
int ans;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> st;
		for(int j = 0; j < st.size(); j++){
			num[j+1] = (num[j+1] << 1) + (st[j]-'0');
		}
	}	
	for(int i = 1;i <= m; i++) dp[0][num[i]]++;
	for(int i = 0; i < n; i++){
		for(int j = n; j >= 1; j--){
			for(int k = 0; k < (1 << n); k++){
				dp[j][k] += dp[j-1][k^(1 << i)];
			}
		}
	}
	ans = n*m;
	for(int i = 0; i < (1 << n); i++){
		int res = 0;
		for(int j = 0; j <= n; j++){
			res += dp[j][i]*min(j,n-j);
		}
		ans = min(ans,res);
	}
	cout << ans;
	return 0;
}
