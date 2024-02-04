#include <bits/stdc++.h>
#define ll long long 
const int maxn = 200005;
const int INF = 2000000005;
using namespace std;
const int maxh = 2;
int n, m, t;
int ind[maxn];
struct Edge {
	int v, w, l, nxt;
};
Edge edge[maxn];
int hd[maxn];
int ecnt;
inline void cont(const int u, const int v, const int w, const int l) {
	auto &e = edge[++ecnt];
	e.v = v;
	e.w = w;
	e.l = l;
	e.nxt = hd[u];
	hd[u] = ecnt;
}


std::queue<int> Q;
int top;
int topo[maxn];
void Topo_sort() {
	for (int i = 1; i <= n; ++i) if (ind[i] == 0) {
			Q.push(i);
		}
	for (int u, v; !Q.empty(); Q.pop()) {
		topo[++top] = u = Q.front();
		for (int e = hd[u]; e; e = edge[e].nxt) if (--ind[v = edge[e].v] == 0) {
				Q.push(v);
			}
	}
}

int pcnt;
int prm[maxn], pre[maxn];
bool np[maxn];
void GetPrime() {
	const int x = 100000;
	for (int i = 2; i <= x; ++i) {
		if (np[i] == false) {
			prm[++pcnt] = i;
			pre[i] = pcnt;
		}
		for (int j = 1, k = prm[j] * i; j <= pcnt; k = prm[++j] * i) if (k <= x) {
				np[k] = true;
				pre[k] = j;
				if ((i % prm[j]) == 0) break;
			} else {
				break;
			}
	}
}
const int pmod[] = {998244353, 1000000009};

int dcnt;
std::vector<int> d, cd;
int make_hash(const int x) {
	ll ret = 0;
	for (int i = 0; i < dcnt; ++i) if (cd[i] != 0) {
			(ret += (d[i] ^ 20020924ll) * (cd[i] ^ 20020301ll)) %= pmod[x];
		}
	return ret;
}

int hsh[maxh][maxn], ph[maxh][maxn];
void Make_hash() {
	for (int i = 1; i <= m; ++i) {
		d.clear();
		cd.clear();
		dcnt = 0;
		for (int x = edge[i].w, pp = 0; x != 1; x /= prm[pre[x]]) if (pp == pre[x]) {
				if (++cd[dcnt - 1] == t) cd[dcnt - 1] = 0;
			} else {
				d.push_back(pre[x]);
				cd.push_back(t != 1);
				++dcnt;
				pp = pre[x];
			}
		for (int j = 0; j < maxh; ++j) {
			hsh[j][i] = make_hash(j);
		}
		for (int j = 0; j < dcnt; ++j) if (cd[j]) {
				cd[j] = t - cd[j];
			}
		for (int j = 0; j < maxh; ++j) {
			ph[j][i] = make_hash(j);
		}
	}
}

std::map<std::pair<int, int>, int> f[maxn];

int main() {
	cin >> n >> m >> t;
	for (int i = 1, u, v, w, l; i <= m; ++i) {
		cin >> u >> v >> w >> l;
		cont(u, v, w, l);
		++ind[v];
	}
	GetPrime();
	Topo_sort();
	Make_hash();
	std::pair<int, int> k;
	int ans = 0;
	for (int i = n, u = topo[i], v; i; u = topo[--i]) {
		for (int e = hd[u]; e; e = edge[e].nxt) {
			v = edge[e].v;
			k = std::make_pair(hsh[0][e], hsh[1][e]);
			f[u][k] = std::max(f[u][k], edge[e].l);
			auto j = std::make_pair(ph[0][e], ph[1][e]);
			f[u][k] = std::max(f[u][k], edge[e].l + f[v][j]);
			ans = std::max(ans, f[u][k]);
		}
	}
	cout << ans;
	return 0;
}




