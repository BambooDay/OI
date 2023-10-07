#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[30][40];
int a[40],cnt = 0;
int k,b;
int dfs(bool limit,int use,int pos){
	if(!pos) return (use == k) ? 1 : 0;
	int &now = dp[use][pos];
	if(!limit && ~now) return now;
	int res = 0;
	int up = (use == k) ? 0 : 1; 
	if(limit) up = min(up,a[pos]);
	for(int i = 0; i <= up; i++){
		res += dfs(limit && i == a[pos], use + (i == 1),pos-1);		
	}
	if( !limit){
		now = res;
	}
	return res;
}
int solve(int n){
	cnt = 0;
	while(n){
		a[++cnt] = n%b;
		n /= b;
	}
	memset(dp,-1,sizeof dp);
	return dfs(1,0,cnt);
}
signed main(){
	int x,y;
	cin >> x >> y >> k >> b;
	cout << solve(y) - solve(x);
	return 0;
}
