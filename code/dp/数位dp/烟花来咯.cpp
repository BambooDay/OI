#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
int n,k;
int a[20];
int dp[20][550];
int dig[5] = {0,0,1,3,7};
int solve(int last,int pos){
	if(pos == n) return 1;
	int &now = dp[last][pos];
	if(~now) return now;
	int res = 0;
	last <<= 1;
	if( a[last] ){
		res += solve(last&dig[k],pos+1);		
	}
	
	res %= mod;
	last |= 1;
	if(a[last]){
		res += solve(last&dig[k],pos+1);
	}
	
	res %= mod;
	now = res;
	return res;
}
int ans = 0;
void check(){
	int x;
	for(int i = 0; i <= pow(2,k)-k; i++){
		x = 0;
		for(int j = 0; j < k; j++) x = x * 2 + a[j+i];
		if(!a[x]) return ;
	}	
	memset(dp,-1,sizeof(dp));
	ans += solve(x&dig[k],pow(2,k));
	ans %= mod;	
}

void dfs(int now){
	if(now == pow(2,k)){
		check();
		return;
	}
	dfs(now+1);
	a[now] = 1;
	dfs(now+1);
	a[now] = 0;
}
signed main(){
	cin >> n >> k;	
	dfs(0);
	cout << ans;
	return 0;
}
