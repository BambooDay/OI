#include <bits/stdc++.h>
#define int long long

using namespace std;
int a[20],len;
int dp[20][5000];
int dfs(int pos, int now, int sum,bool limit){
	if(!pos){
		return !sum;
	}
	if(dp[pos][sum+200]!=-1 && !limit) return dp[pos][sum+200];
	int up = (limit?a[pos]:9);
	int res = 0;
	for(int i = 0; i <= up; i++){
		res += dfs(pos-1,now,sum+(pos-now)*i,limit&&(i==up));
	}
	if(!limit) dp[pos][sum+200] = res;
	return res;
}
int ans = 0;
void solve(int x,int op){
	len = 0;
	while(x){
		a[++len] = x%10;
		x /= 10;
	}
	for(int i = 1; i <= len; i++){
		memset(dp,-1,sizeof dp);
		ans += dfs(len,i,0,1)*op; 
	}  
	ans -= (len-1)*op;
}
signed main(){
	int l,r;
	cin >> l >> r;
	solve(l-1,-1);
	solve(r,1);
	cout << ans <<endl;
	return 0;
}
