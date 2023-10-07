#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
ll sum[1005];
ll dp[1005];
int main(){
	scanf("%d",&n);
//	cin >> n;
	dp[1] = 1,sum[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = sum[i/2]+1;
		sum[i] = sum[i-1]+dp[i];
	}
//	for(int i =1;i <= n; i++){
//		cout << dp[i] << " ";
//	}
//	cout<< dp[n];
	printf("%lld",dp[n]);
	return 0;
}
