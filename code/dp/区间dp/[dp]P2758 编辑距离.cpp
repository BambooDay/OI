#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string a, b;
int la,lb;
int dp[N][N];
int main(){
	cin >> a>> b;
	la = a.size();
	lb = b.size();
	a = " " + a;
	b = " " + b;
	for(int i = 1;i <= la;i++) dp[i][0] = i;
	for(int i = 1;i <= lb;i++) dp[0][i] = i;
	for(int i = 1; i <= la; i++){
		for(int j = 1; j <= lb; j++){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
			if(a[i] == b[j]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
			else dp[i][j] = min(dp[i-1][j-1] + 1,dp[i][j]);
		}
	}
	cout << dp[la][lb];
	return 0;
}
