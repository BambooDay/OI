#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m;
ll w[50],c[50];
ll dp[330];
int main(){
	cin >> m >> n;
	for(int i = 1;i <= n; i++) cin >> w[i] >> c[i];
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++){
			dp[j] = max(dp[j],dp[j-w[i]] + c[i]);
		}
	}
	cout <<"max="<< dp[m];
	return 0;
}
