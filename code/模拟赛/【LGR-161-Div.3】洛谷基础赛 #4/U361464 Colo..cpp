#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[600],b[600];
set<int> s[600],apr;
vector<int> e[600];
int dp[600][600];
signed main(){
	cin >> n >> k;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		apr.insert(a[i]);
	} 
	for(int i = 1;i <= n; i++) cin >> b[i];
	for(auto i : apr){
		for(auto j : apr){
			if(i <= j) continue;
			s[i].insert(j);
		}
	}		
	for(int i = 1;i <= n; i++){
		bool f = 0;
		for(int j = 1; j <= n; j++){
			if(a[j] == i) f = 1;
			if(f && a[j] < i){
				if(s[i].count(a[j])) s[i].erase(a[j]); 
			}
		}
	}
	
	memset(dp,-0x3f,sizeof dp);
	for(auto i : apr){
		dp[i][1] = b[i];
		for(int j = 2; j <= k; j++){
			for(auto v : s[i]){
				if(v == i) continue;
				dp[i][j] = max(dp[i][j],dp[v][j-1] + b[i]);
			}
		} 
	}
	int ans = -1;
	for(auto i : apr){
		ans = max(ans,dp[i][k]);
	}
	cout << ans;
	return 0;
}
