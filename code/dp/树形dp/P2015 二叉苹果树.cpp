#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 200+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[N],node[N],val[N],idx;
void add(int u,int v,int w){
	node[++idx] = v;
	val[idx] = w;
	ne[idx] = h[u];
	h[u] = idx;
}
int n, q;
int dp[N][N];
void dfs(int pos,int fa){
	dp[pos][0] = 0;
	int ls = 0,rs = 0;
	for(int i = h[pos];i;i=ne[i]){
		if(node[i] ==fa) continue;
		dfs(node[i],pos);
		if(ls) rs = i;
		else ls = i;
	} 
	if(!ls) return;
	for(int i = 1; i <= q; i++){
		dp[pos][i] = max(dp[pos][i],dp[node[ls]][i-1] + val[ls]);
		dp[pos][i] = max(dp[pos][i],dp[node[rs]][i-1] + val[rs]);
		for(int j = 0; j <= i-2; j++){
			dp[pos][i] = max(dp[pos][i],dp[node[ls]][j] + dp[node[rs]][i-2-j] + val[rs] + val[ls]);
		}
	}
}
int main(){
	cin >> n >> q;
	memset(dp,-0x3f,sizeof dp);
	for(int i =1;i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout << dp[1][q];
	return 0;
}
