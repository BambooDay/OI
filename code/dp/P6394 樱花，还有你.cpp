#include <bits/stdc++.h>
const int mod = 10086001;
const int N = 5e3+10;
using namespace std;
int n, k,dp[N],sum[N];
int a[N];
int main(){
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1; i <= k; i++){
		cin >> a[i];
		cnt += a[i];
	}	
	if(cnt < n){
		puts("impossible");
		return 0;
	}
	sum[0] = 1;
	for(int i = 1; i <= a[1]; i++){
		sum[i] = sum[i-1]+1;
	}
	for(int i = a[1]+1; i <= n; i++){
		sum[i] = sum[i-1];
	}
	int ans = 0;
	if(a[1] >= n) ans++;
	for(int i = 2;i <= k; i++){
		for(int j = 0; j <= n; j++){
			if(j > a[i]){
				dp[j] = ((sum[j] - sum[j-a[i]-1]) % mod + mod ) % mod;
			}else{
				dp[j] = sum[j] % mod;
			}
		}
		sum[0] = dp[0];
		for(int j = 1; j <= n; j++){
			sum[j] = (sum[j-1] + dp[j]) % mod;
		}
		ans = (ans + dp[n]) % mod;
	}
	cout << ans % mod;
	return 0;
}
