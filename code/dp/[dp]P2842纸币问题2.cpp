#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
int n, a[N],w;
int dp[M];
int main(){
	cin >> n >> w;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[0] = 1;
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= n; j++){
			if(a[j] <= i){
				dp[i] += dp[i-a[j]];
				dp[i] %= mod;
			}
		}
	}
	cout << dp[w];
	return 0;
}
