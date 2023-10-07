#include <bits/stdc++.h>

const int N = 1e5+7;
const long long mod = 1e9+7;

using namespace std;
vector<int> e[N];
int dp[N][110][2][2],tmp[110][2][2];
int siz[N];
int n, k;
inline int add(int x, long long y) {
	if (y >= mod) y %= mod;
	for (x += y; x >= mod; x -= mod);
	return x;
}
void dfs(int x, int fa){
	siz[x] = dp[x][0][0][0] = dp[x][1][1][0] = 1;
	for(auto to : e[x]){
		if(to == fa) continue;
		dfs(to,x);
		for(int i = 0; i <= min(siz[x],k); i++){
				tmp[i][0][0] = dp[x][i][0][0];
				dp[x][i][0][0] = 0;
				tmp[i][0][1] = dp[x][i][0][1];
				dp[x][i][0][1] = 0;
				tmp[i][1][0] = dp[x][i][1][0];
				dp[x][i][1][0] = 0;
				tmp[i][1][1] = dp[x][i][1][1];
				dp[x][i][1][1] = 0;
		}
		for(int i = 0; i <= min(siz[x],k); i++){
			for(int j = 0; j <= min(siz[to],k-i); j++){
					dp[x][i + j][0][0] = add(dp[x][i + j][0][0], 1ll * tmp[i][0][0] * dp[to][j][0][1]);
	
					dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][1] * (dp[to][j][0][1] + dp[to][j][1][1]));
					dp[x][i + j][0][1] = add(dp[x][i + j][0][1], 1ll * tmp[i][0][0] * dp[to][j][1][1]);
	
					dp[x][i + j][1][0] = add(dp[x][i + j][1][0], 1ll * tmp[i][1][0] * (dp[to][j][0][0] + dp[to][j][0][1]));
	
					dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][0] * (dp[to][j][1][0] + dp[to][j][1][1]));
					dp[x][i + j][1][1] = add(dp[x][i + j][1][1], 1ll * tmp[i][1][1] * (1ll * dp[to][j][0][0] + dp[to][j][0][1] + 1ll * dp[to][j][1][0] + dp[to][j][1][1]));	
			}
		}
		siz[x] += siz[to];
	}
}
signed main(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	cout << (dp[1][k][0][1] + dp[1][k][1][1]) % mod;
	return 0;
}
