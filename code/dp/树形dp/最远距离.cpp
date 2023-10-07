#include <bits/stdc++.h>;
using namespace std;
const int N = 1e4 + 5;
vector<int> e[N], val[N];
int dp[N], max_len, s;
void dfs(int x, int f, int len) {
	if (max_len <= len) { 
		s = x;
		max_len = len;
	}
	for (int i = 0; i < e[x].size(); i++) {
		int to = e[x][i];
		if (to == f) continue;
		dfs(to, x, len + val[x][i]);
		dp[to] = max(dp[to], len + val[x][i]); 
	}
}
int main() {
	int n;
	cin >> n;
	int a, b;
	for (int i = 2; i <= n; i++) {
		cin >> a >> b;
		e[i].push_back(a); 
		val[i].push_back(b);
		e[a].push_back(i);
		val[a].push_back(b);
	}
	s = 0;
	max_len = 0;
	dfs(1, -1, 0); 
	dfs(s, -1, 0);
	dfs(s, -1, 0); 
	for (int i = 1; i <= n; i++){
		cout << dp[i] << endl;
	}
	return 0;
}
