#include <bits/stdc++.h>
const int N = 4e5 + 10;
using namespace std;

int a[N][3];
int ans[N], nxt[N];
int p[N], w[N], vis[N][3];
int fa[N], head[N], tail[N];

int find(int x) {
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

void merge (int u, int v, int p) {
	int fu = find(u), fv = find(v);
	if (fu == fv) return ;
	if (fu > fv) swap (fu, fv);
	if (fu == 1 && p != -1) { 
		for (int use = head[fv]; use; use = nxt[use]) ans[use] = p;
	}
	fa[fv] = fu;
	nxt[tail[fu]] = head[fv];
	tail[fu] = tail[fv];
}

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d", &a[i][1], &a[i][2]);
		ans[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		scanf ("%d%d", &p[i], &w[i]);
		vis[p[i]][w[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) fa[i] = head[i] = tail[i] = i, nxt[i] = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i][1] && a[i][1] != -1) merge (i, a[i][1], -1);
		if (!vis[i][2] && a[i][2] != -1) merge (i, a[i][2], -1);
	}
	for (int i = m - 1; i >= 0; --i) {
		int u = p[i], v = a[p[i]][w[i]];
		merge (u, v, i);
	}
	for (int i = 1; i <= n; ++i) printf("%d\n",ans[i]);
	return 0;
}

