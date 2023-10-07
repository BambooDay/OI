#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e4+10;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
int h[N],ne[M],node[M],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int val[N];
struct NODE{
	int u,v,w;
}e[M];
bool cmp(NODE a, NODE b){
	return a.w > b.w;
}
int fa[N],cnt,ff[N];
int get(int x){
	return x == ff[x] ? x: ff[x] = get(ff[x]);
}
int siz[N],son[N],tp[N],dep[N];
void dfs1(int pos,int f){
	siz[pos] = 1;
	for(int i = h[pos];i;i=ne[i]){
		int to = node[i];
		if(to == f) continue;
		dep[to] = dep[pos]+1;
//		cout << to << ' ' << dep[to] << endl; 
		fa[to] = pos;
		dfs1(to,pos);
		siz[pos] += siz[to];
		if(siz[to] > siz[son[pos]]) son[pos] = to;
	}
}
void dfs2(int pos,int top){
	tp[pos] = top;
	if(son[pos]) dfs2(son[pos],top);
	for(int i = h[pos];i;i=ne[i]){
		int to = node[i];
		if(to == fa[pos] || to == son[pos]){
			continue;
		}
		dfs2(to,to);
	}
}

void kruskal(){
	for(int i =1;i <= n; i++) ff[i] = i;
	sort(e+1,e+1+m,cmp);
	for(int i =1;i <= m; i++){
		int fu = get(e[i].u),fv = get(e[i].v);
		if(fu != fv){
			val[++cnt] = e[i].w;
			ff[cnt] = ff[fu] = ff[fv] = cnt;
			add(fu,cnt);
			add(cnt,fu);
			add(fv,cnt);
			add(cnt,fv);
//			cout << cnt << endl;
		}
	}
	for(int i = 1; i<= cnt;i++){
		if(!siz[i]){
			int f = get(i);
			dfs1(f,0);
			dfs2(f,f);
		}
	}
}

int LCA(int x, int y){
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]]) y = fa[tp[y]];
		else x = fa[tp[x]];
//		cout << dep[y] << endl;
	}
	return dep[x] < dep[y] ? x: y; 
}

int main(){
	cin >> n >> m;
	for(int i =1; i<= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	cnt = n;
	int t;
	cin >> t;
	kruskal();
	while(t--){
		int x, y;
		cin >> x >> y;
//		cout << LCA(x,y) << endl; 
		if(get(x) != get(y)) puts("-1");
		else cout << val[LCA(x,y)] << endl;
	}
	return 0;
}
