#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
namespace Sub1{
	ll dp[20][20][350][350];
	int p[20];
	ll v[20];
	int sum = 0;
	void solve(){
		for(int i = 1;i <= n; i++){
			cin >> v[i] >> p[i];
			sum += p[i];
		} 	
		memset(dp,-0x3f,sizeof dp);
		dp[0][0][0][0] = 0;
		for(int i = 1;i <= n; i++){
			for(int j = 0;j <= k; j++){
				for(int a = 0; a <= sum; a++){
					for(int b = 0; b <= sum; b++){
						dp[i][j][a][b] = dp[i-1][j][a][b];
						if(a >= p[i]){
							dp[i][j][a][b] = max(dp[i][j][a][b],dp[i-1][j][a-p[i]][b]+v[i]);
						}
						if(b >= p[i]){
							dp[i][j][a][b] = max(dp[i][j][a][b],dp[i-1][j][a][b-p[i]]+v[i]);
						}
						if(j == 0) continue;
						if(a >= p[i]*2){
							dp[i][j][a][b] = max(dp[i][j][a][b],dp[i-1][j-1][a-p[i]*2][b]+v[i]);
						}
						if(b > p[i]*2){
							dp[i][j][a][b] = max(dp[i][j][a][b],dp[i-1][j-1][a][b-p[i]*2]+v[i]);
						}
					}
				}
			}
		}
		ll ans =-1e18;
		for(int i = 0; i <= k; i++){
			for(int a = 0; a <= sum*2; a++){
				ans = max(ans,dp[n][i][a][a]);
			}
		}
		cout << ans << endl;
	}
}
namespace Sub2{
	ll dp[27][380][380];
	int p[27];
	ll v[27];
	int sum = 0;
	void solve(){
		for(int i = 1;i <= n; i++){
			cin >> v[i] >> p[i];
			sum += p[i];
		} 	
		memset(dp,-0x3f,sizeof dp);
		dp[0][0][0] = 0;
		for(int i = 1;i <= n; i++){
			for(int a = 0; a <= sum; a++){
				for(int b = 0; b <= sum; b++){
					dp[i][a][b] = dp[i-1][a][b];
					if(a >= p[i]){
						dp[i][a][b] = max(dp[i][a][b],dp[i-1][a-p[i]][b]+v[i]);
					}
					if(b >= p[i]){
						dp[i][a][b] = max(dp[i][a][b],dp[i-1][a][b-p[i]]+v[i]);
					}
					if(a >= p[i]*2){
						dp[i][a][b] = max(dp[i][a][b],dp[i-1][a-p[i]*2][b]+v[i]);
					}
					if(b > p[i]*2){
						dp[i][a][b] = max(dp[i][a][b],dp[i-1][a][b-p[i]*2]+v[i]);
					}
				}
			}
			
		}
		ll ans =-1e18;
		for(int a = 0; a <= sum; a++){
			ans = max(ans,dp[n][a][a]);
		}
		cout << ans << endl;
	}
}
namespace Sub3{
	int p[105];
	ll v[105];
	ll sum = 0;
	void solve(){
		for(int i = 1;i <= n; i++){
			cin >> v[i] >> p[i];
			if(v[i]>= 0) sum += v[i];
		}
		cout << sum << endl;
	}	
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> k;
	if(n <= 18){
		Sub1::solve();
	}else if(k == 0){
		Sub2::solve();
	}else{
		Sub3::solve();
	}
	return 0;
}
