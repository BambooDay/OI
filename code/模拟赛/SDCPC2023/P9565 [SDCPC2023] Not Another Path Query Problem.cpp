#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 5e5+10;
#define ll long long
using namespace std;
int n, m, q;
int u[M],v[M];
long long V;
bool ans[M];

vector<pair<int,ll> > e[N];
int lt[N];

void bfs(int st, long long t) {
	queue<int> q;
	q.push(st);
	lt[st] = st;
	while (!q.empty()) {
		int xx = q.front();
		q.pop();
		for (auto i : e[xx]) {
			int to = i.first;
			long long val = i.second;
			if (lt[to] || (val & t) != t) continue;
			q.push(to);
			lt[to] = st;
		}
	}
}

void solve(ll t) {
	memset(lt, 0, sizeof lt);
	for (int i = 1; i <= n; i++){
		if (!lt[i]) {
			bfs(i, t);
		}
	} 
	for (int i = 1; i <= q; i++){
		ans[i] = ans[i] || lt[u[i]] == lt[v[i]];
	} 
}

int main() {
	cin >> n >> m >> q>> V;
	for (int i = 1; i <= m; i++) {
		int x, y;
		ll z;
		cin >> x >> y >> z;
		e[x].push_back(make_pair(y,z));
		e[y].push_back(make_pair(x,z));
	}
	for (int i = 1; i <= q; i++) cin >> u[i] >> v[i];

	if (V == 0){
		solve(0);
	}else{
		for (ll t = V; t < (1LL << 60); t += t & (-t)){
			solve(t);
		} 
	} 
	for (int i = 1; i <= q; i++){
		if (ans[i]){
			puts("Yes");
		} else{
			puts("No");
		} 
	}
	return 0;
}
