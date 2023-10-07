#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;
int h[N], ne[N], node[N], val[N];
int idx = 0;
void add(int u, int v, int w) {
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
struct Node {
	int x, y, z;
	bool friend operator <(const Node a, const Node b) {
		return a.z < b.z;
	}
} e[N];
vector<Node> no;
int fa[N];
int n, m;
ll sum = 0, ans = INF;
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void kruskal() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		Node t = e[i];
		int fx = get(e[i].x), fy = get(e[i].y);
		if (fx != fy) {
			add(e[i].x, e[i].y, e[i].z);
			add(e[i].y,e[i].x,e[i].z);
			fa[fx] = fy;
			sum += e[i].z;
		} else {
			no.push_back(t);
		}
	}
}
int dep[N], f[N][20], ma[2][N][20];
void init(int fa, int x, int vv) {
	dep[x] = dep[fa] + 1;
	f[x][0] = fa;
	ma[0][x][0] = vv;
	ma[1][x][0] = -INF;
	for (int i = 1; i <= 18; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		ma[0][x][i]=max(ma[0][x][i-1],ma[0][f[x][i-1]][i-1]);
		ma[1][x][i]=max(ma[1][x][i-1],ma[1][f[x][i-1]][i-1]);
		if(ma[0][x][i-1]>ma[0][f[x][i-1]][i-1]) ma[1][x][i]=max(ma[1][x][i],ma[0][f[x][i-1]][i-1]);
        else if(ma[0][x][i-1]<ma[0][f[x][i-1]][i-1]) ma[1][x][i]=max(ma[1][x][i],ma[0][x][i-1]);		
	}
	for(int i = h[x]; i; i = ne[i]){
		if(node[i] != fa){
			init(x,node[i],val[i]);
		}
	}
}
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 18; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]){
			x = f[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 18; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i],y = f[y][i];
		}
	}
	return f[x][0];
}
int work(int u, int v, int w){
	int res = - INF;
	for(int i = 18; i >= 0; i--){
		if(dep[f[u][i]] >= dep[v]){
			if(w != ma[0][u][i]) res = max(res,ma[0][u][i]);
			else res = max(res,ma[1][u][i]);
			u = f[u][i];
		}
	}
	return res;
}

int main() {
	cin >> n >> m;
	for(int i =1; i<= m; i++){
		cin >> e[i].x >> e[i].y >> e[i].z;
	}
	sort(e+1,e+m+1);
	kruskal();
	dep[1] = 1;
	init(0,1,0);
	int ans = INF;
	for(Node to: no){
		int l = LCA(to.x,to.y);
		int res = max(work(to.x,l,to.z),work(to.y,l,to.z));
		ans = min(ans,to.z-res);
	}
	cout << ans + sum;
	return 0;
}
