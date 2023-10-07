#include <bits/stdc++.h>
const int N = 1e6+10;
#define int long long
using namespace std;
int dp[N];
int k[N],c[N];
int n, m, cnt;

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> k[i];
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		cnt += c[i] * k[i];
	}	
	dp[0] = 1;
	for(int i = 1;i <= n; i++){
		for(int j = cnt; j >= 0; j--){
			for(int p = 0; p <= k[i] && p*c[i] <= j; p++){
				dp[j] = max(dp[j],dp[j-p*c[i]]*p);
			}
		}
	}
	int ans = 0;
	while(ans <= cnt && dp[ans] < m) ans++;
	cout << ans;
	return 0;
}
