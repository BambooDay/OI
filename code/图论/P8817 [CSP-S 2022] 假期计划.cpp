#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2500 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m, k;
vector <int> f[N];
vector <int> e[N];
ll w[N];
bool vis[N][N];
void bfs(int s) {
	queue<int> q;
	q.push(s);
	int dis[N];
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t != s) {
			vis[s][t] = 1;
			if(t != 1 && vis[1][t]){
				f[s].push_back(t);
				sort(f[s].begin(), f[s].end(), [](int u, int v) {
					return w[u] > w[v];
				});
				if(f[s].size() > 3) f[s].pop_back();
			}
		}
		if(dis[t] == k+1) continue;
		for (int to : e[t]) {
			if(dis[to] == INF){
				dis[to] = dis[t]+1;
				q.push(to);
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++) {
		cin >> w[i];
	}
	while (m--) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	ll ans = 0;
	for(int b = 2; b <= n; b++){
		for(int c = 2; c <= n; c++){
			if(vis[b][c]){
				for(int a : f[b]){
					for(int d : f[c]){
						if(a!=c && b != d && a != d)
							ans = max(ans,w[a]+w[b]+w[c]+w[d]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
