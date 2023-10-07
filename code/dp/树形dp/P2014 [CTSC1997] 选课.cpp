#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 400+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n,m;
vector<int> son[N];
int dp[N][N];
void dfs(int pos){
	for(int to : son[pos]){
		dfs(to);
		for(int j = m+1; j >= 1; j--){
			for(int k = 0; k < j ;k++){
				dp[pos][j] = max(dp[pos][j],dp[pos][j-k]+dp[to][k]);
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int k, s;
		cin >> k >> s;
		son[k].push_back(i);
		dp[i][1] = s;
	}
	dfs(0);
	cout << dp[0][m+1];
	return 0;
}
