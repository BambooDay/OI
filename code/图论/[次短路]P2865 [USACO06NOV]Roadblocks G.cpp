#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
int dis1[N], dis2[N];
struct node {
	int v, w;
	friend bool operator < (node a, node b) {
		return a.w > b.w;
	}
};
vector <node> G[N];
void Dijkstra() {
	priority_queue <node> que;
	fill(dis1, dis1 + n + 1, INF);
	fill(dis2, dis2 + n + 1, INF);
	int start = 1;
	dis1[start] = 0;
	que.push((node) {start, 0});
	node q;
	int v, w;
	while (!que.empty()) {
		q = que.top();
		que.pop();
		v = q.v, w = q.w;
		if (dis2[v] < w)	continue;
		int to_v, to_w;
		for (int i = 0 ; i < G[v].size() ; i++) {
			to_v = G[v][i].v, to_w = G[v][i].w + w;
			if (dis1[to_v] > to_w) {
				que.push((node) {to_v, to_w});
				swap(dis1[to_v], to_w);
			}
			if (dis2[to_v] > to_w && dis1[to_w] < to_w) {
				dis2[to_v] = to_w;
				que.push((node) {to_v, to_w});
			}
		}
	}

}

int main(){
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int u, v, w;
		scanf(" %d %d %d", &u, &v, &w);
		G[u].push_back((node) {v, w});
		G[v].push_back((node) {u, w});
	}
	Dijkstra();
	cout << dis2[n];
	return 0;
}
