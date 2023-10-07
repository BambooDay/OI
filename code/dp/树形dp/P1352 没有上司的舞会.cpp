#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 6e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
vector<int> son[N];
int a[N];
int n;
ll dp[N][2];//0 unattened 1 attened
void dfs(int pos){
	dp[pos][0] = dp[pos][1] = 0;
	dp[pos][1] += a[pos];
	for(int to : son[pos]){
		dfs(to);
//		if(pos == 5) cout << dp[to][0] << ' ';
		dp[pos][0] = max(dp[pos][0],dp[pos][0] + max(dp[to][1],dp[to][0]));
		dp[pos][1] = max(dp[pos][1],dp[pos][1] + dp[to][0]);
	}
}
bool fa[N];
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		cin >> a[i];
	}	
	for(int i =1;i < n; i++){
		int l, k;
		cin >> l >> k;
		son[k].push_back(l);
		fa[l] = 1;
	}
	int rt;
	for(int i =1;i <= n; i++){
		if(!fa[i]){
			rt = i;
			break;
		}
	}
	dfs(rt);
	for(int i =1;i <= n; i++){
//		cout << dp[i][1] << " " << dp[i][0] << endl;
	} 
	cout << max(dp[rt][0],dp[rt][1]);
	return 0;
}
/*
7
1
1
1
1
-128
1
1
1 3
2 3
6 4
7 4
4 5
3 5 
*/ 
