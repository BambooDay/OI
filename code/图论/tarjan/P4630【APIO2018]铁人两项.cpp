#include <bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;
int n, m, cnt;
vector<int> G[N], T[N << 1];
long long ans;
int dfn[N], low[N], dfc, num;
int val[N << 1];
stack<int> st;
void tarjan(int pos) {
	low[pos] = dfn[pos] = ++dfc;
	st.push(pos);
	num++;
	for (int v : G[pos]) {
		if (!dfn[v]) {
			tarjan(v);
			low[pos] = min(low[pos], low[v]);
			if (low[v] == dfn[pos]) {
				val[++cnt] = 2;
				while (st.top() != v) {
					int x = st.top();
					st.pop();
					T[cnt].push_back(x);
					T[x].push_back(cnt);
					val[cnt]++;
				}
				st.pop();
				T[cnt].push_back(v);
				T[v].push_back(cnt);
				T[cnt].push_back(pos);
				T[pos].push_back(cnt);
			}
		} else low[pos] = min(low[pos], dfn[v]);
	}
}
int siz[N << 1];
void dfs(int pos, int fa) {
	siz[pos] = (pos <= n);
	for (int v : T[pos]) {
		if (v == fa) continue;
		dfs(v, pos);
		ans += 2ll * val[pos] * siz[pos] * siz[v];
		siz[pos] += siz[v];
	}
	ans += 2ll * val[pos] * (num - siz[pos]) * siz[pos];
}
int main() {
	cin >> n >> m;
	cnt = n;
	for (int i = 1; i <= n; i++) val[i] = -1;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			num = 0;
			tarjan(i);
			st.pop();
			dfs(i, 0);
		}
	}
	//for(int i = 1;i <= cnt; i++) cout << siz[i] << ' ';
	cout << ans;
	return 0;
}
