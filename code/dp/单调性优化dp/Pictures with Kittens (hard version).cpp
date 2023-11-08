#include <bits/stdc++.h>
#define int long long
const int N = 5005;

using namespace std;

int a[N];
int n,k,m;
int dp[N][N];

signed main(){
	cin >> n >> k >> m;
	memset(dp,-0x3f,sizeof dp);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	} 
	if(n/k>m) {
		cout << -1;
		return 0;
	}
	dp[0][0] = 0;
	for(int j = 1;j <= m; j++){
		deque<int> q;
		q.push_back(0);
		for(int i = 1; i <= n; i++){
			while(!q.empty()&&q.front() < i-k) q.pop_front();
			if(!q.empty()) dp[i][j] = dp[q.front()][j-1]+a[i];
			while(!q.empty()&&dp[q.back()][j-1] <= dp[i][j-1]) q.pop_back();
			q.push_back(i);
		}
	}
	int ans = 0;
	for(int i = n-k+1; i <= n; i++) ans = max(ans,dp[i][m]);
	cout << ans;
	return 0;
}
