#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define int long long

const int maxn = 1010;

struct edge {
	int v, c, dis;
};
vector<edge> g[maxn];

queue<int> q;
int a[maxn];
int cost[maxn], sum[maxn];
bool in_queue[maxn];
int inf;

void spfa(int s) {
	memset(cost, 127, sizeof(cost));
	memset(sum, 127, sizeof(sum));
	inf = cost[0];
	cost[s] = sum[s] = 0;
	q.push(s);
	in_queue[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		in_queue[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if (cost[v] > cost[u] + g[u][i].c ||
			        (cost[v] == cost[u] + g[u][i].c &&
			         sum[u] + g[u][i].dis < sum[v])) {
				cost[v] = cost[u] + g[u][i].c;
				sum[v] = sum[u] + g[u][i].dis;
				if (!in_queue[v]) {
					q.push(v);
					in_queue[v] = true;
				}
			}
		}
	}
	return;
}

signed main() {
	int s, t, m;
	cin >> s >> t >> m;
	for (int i = 1; i <= m; i++) {
		int c, n;
		cin >> c >> n;
		edge tmp;
		tmp.c = c;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (int j = 1; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				tmp.v = a[k];
				tmp.dis = k - j;
				g[a[j]].push_back(tmp);
			}
		}
	}
	spfa(s);
	if (cost[t] == inf || sum[t] == inf) {
		cout << -1 << ' ' << -1 << endl;
	} else {
		cout << cost[t] << ' ' << sum[t] << endl;
	}
	return 0;
}

