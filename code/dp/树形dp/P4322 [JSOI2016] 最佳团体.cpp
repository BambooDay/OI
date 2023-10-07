#include <bits/stdc++.h>
using namespace std;


const int maxn = 3000, inf = 1e9 + 7;
int n, k;
struct node {
	int to, nxt;
} ed[maxn];
int head[maxn], tot;
void add(int u, int to) {
	ed[++tot].to = to;
	ed[tot].nxt = head[u];
	head[u] = tot;
}
int siz[maxn], dfn[maxn], pos[maxn], cnt;
void dfs(int x) {
	siz[x] = 1;
	for (int i = head[x]; i; i = ed[i].nxt) {
		int to = ed[i].to;
		dfs(to);
		siz[x] += siz[to];
	}
	dfn[x] = ++cnt, pos[cnt] = x;
}
double val[maxn], f[maxn][maxn];
int p[maxn], s[maxn];
bool check(double x) {
	for (int i = 0; i <= cnt; i++)
		for (int j = 1; j <= k; j++)
			f[i][j] = -inf;
	for (int i = 1; i <= n; i++)
		val[i] = (double)p[i] - x * s[i];
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= k; j++) {
			f[i][j] = max(f[i - 1][j - 1] + val[pos[i]], f[i - siz[pos[i]]][j]);
		}
	}
	return f[cnt][k] > 0;
}
int main() {
	cin >> k >> n;
	k++;
	for (int i = 1; i <= n; i++) {
		cin>> s[i] >> p[i];
		int x;
		cin >> x;
		add(x, i);
	}
	dfs(0);
	double l = 0, r = 100000, eps = 1e-4;
	while (r - l >= eps) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.3lf\n", l);
	return 0;
}
