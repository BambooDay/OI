#include <bits/stdc++.h>
#define int long long
const int INF = 0xfffffffffffffff;
const int N = 3e5 + 10;
using namespace std;
struct edge {
	int u, v, w, ne;
} e[N << 1];
int n, num, s, u, v, head[N];
int dis[N], pre[N], mp[N];
int ans = 1e15, sum[N], dis1[N];
int que[N] = {INF}, t = 0, h = 0;

void add(int u, int v, int w) {
	e[++ num].u = u, e[num].v = v, e[num].w = w;
	e[num].ne = head[u], head[u] = num;
}
void dfs(int now, int fat, int sum, bool flag) {
	if (flag) pre[now] = fat, mp[now] = sum;
	dis[now] = dis[fat] + sum;
	for (int i = head[now]; i; i = e[i].ne) {
		if (e[i].v != fat) dfs(e[i].v, now, e[i].w, flag);
	}
}
void get_road() {
	dfs(1, 0, 0ll, 0);
	for (int i = 1, maxdis = 0; i <= n; i ++) {
		if (dis[i] > maxdis) u = i, maxdis = dis[i];
	}
	dfs(u, 0, 0ll, 1);
	for (int i = 1, maxdis = 0; i <= n; i ++) {
		if (dis[i] > maxdis) v = i, maxdis = dis[i];
	}
}
void bfs() {
	memset(dis, 63, sizeof(dis));
	std :: queue <int> q, from;
	for (int i = v; i != 0; i = pre[i]) {
		q.push(i), from.push(i), dis[i] = 0;
	}

	for (; !q.empty();) {
		int now = q.front(), fr = from.front();
		q.pop(), from.pop();
		for (int i = head[now]; i ; i = e[i].ne) {
			if (dis[e[i].v] >= INF) {
				dis[e[i].v] = dis[now] + e[i].w;
				dis1[fr] = max(dis1[fr], dis[e[i].v]);
				q.push(e[i].v), from.push(fr);
			}
		}
	}
}
void solve() {
	pre[n + 1] = v;
	for (int i = n + 1; i != 0; i = pre[i]) {
		sum[pre[i]] = sum[i] + mp[i];
	}

	for (int l = v, r = v; l != 0 && r != u; l = pre[l]) {
		int last = r;
		++ h;
		while (sum[r] - sum[l] <= s && r != 0) {
			last = r, r = pre[r];
			if (r != 0 && sum[r] - sum[l] <= s) {
				for (; dis1[r] >= que[t] && t >= h;) t--;
				que[++ t] = dis1[r];
			}
		}
		if (r == 0 || sum[r] - sum[l] > s) r = last;

		int now = max(sum[l], sum[u] - sum[r]);
		now = max(now, que[h]);
		ans = min(now, ans);
	}
}
signed main() {
	cin >> n >> s;
	for (int i = 1; i < n ; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
	get_road();
	bfs();
	solve();
	printf("%lld", ans);
}
