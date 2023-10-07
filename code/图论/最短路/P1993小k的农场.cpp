#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, elast[5005], dis[5005], num[5005];
bool vis[5005];

struct edge {
	int to, len, next;
} e[15005];

queue<int> q;

void add (int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].len = w;
	e[cnt].next = elast[u];
	elast[u] = cnt;
}

bool spfa (int x) {
	dis[x] = 0;
	q.push(x);
	vis[x] = true;
	num[x]++;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = elast[u]; i != 0; i = e[i].next)
			if (dis[e[i].to] > dis[u] + e[i].len) {
				dis[e[i].to] = dis[u] + e[i].len;
				if (!vis[e[i].to]) {
					q.push(e[i].to);
					vis[e[i].to] = true;
					num[e[i].to]++;
					if (num[e[i].to] == n + 1)
						return false;
				}
			}
	}
	return true;
}

int main () {
	scanf("%d %d", &n, &m);
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		int opt;
		scanf("%d", &opt);
		switch (opt) {
			case 1: {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				add(a, b, -c);
				break;
			}
			case 2: {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				add(b, a, c);
				break;
			}
			case 3: {
				int a, b;
				scanf("%d %d", &a, &b);
				add(a, b, 0);
				add(b, a, 0);
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		add(n + 1, i, 0);
	bool flag = spfa(n + 1);
	if (!flag) {
		printf("No");
		return 0;
	}
	printf("Yes");
	return 0;
}