#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n,m,fa[N];
int cu,cv,cw,ch;
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}
int tr[N];
void modify(int x, int y){
	for(int i = x; i <= n; i += (i&-i)){
		tr[i] += y;
	}
}
int query(int x){
	int ans = 0;
	for(int i = x; i ; i -= (i&-i)) ans += tr[i];
	return ans;
}
int h[N],node[N<<1],ne[N<<1],val[N<<1],idx;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int siz[N],f[N],tp[N],hson[N],dep[N],dfn[N],dfw[N],tot;
void dfs1(int pos, int ff){
	siz[pos] = 1;
	f[pos] = ff;
	dep[pos] = dep[ff]+1;
	for(int i = h[pos]; i; i = ne[i]){
		int to = node[i];
		if(to == ff) continue;
		dfs1(to,pos);
		siz[pos] += siz[to];
		if(siz[hson[pos]] < siz[to]) hson[pos] = to;
	}
}
void dfs2(int pos, int top, int w){
	dfn[pos] = ++tot;
	dfw[tot] = w;
	tp[pos] = top;
	for(int i = h[pos]; i; i = ne[i]){
		if(node[i] == hson[pos] && hson[pos] != 0) dfs2(hson[pos],top,val[i]);
	}
	for(int i = h[pos]; i; i = ne[i]){
		int to = node[i];
		if(to == hson[pos] || to == f[pos]) continue;
		dfs2(to,to,val[i]);
	}
}
int ask(int x, int y){
	if(x == y) return 0;
	int res = 0;
	while(tp[x] != tp[y]){
		if(dep[tp[x]] < dep[tp[y]]){
			swap(x,y);
		}
		res += query(dfn[x]) - query(dfn[tp[x]]-1);
		x = f[tp[x]];
	}
	if(dfn[x] > dfn[y]) swap(x,y); 
	res += query(dfn[y]) - query(dfn[x]);
	return res;
}
struct esge{
	int u,v,w;
}e[N];
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++){
		int x,y,z;
		cin >> x >> y >> z;
		if(find(x) != find(y)) fa[find(x)] = find(y);
		else{
			cu = x,cv = y,cw = z,ch = i;
			continue;
		} 
		add(x,y,z);
		add(y,x,z);
		e[i] = {x,y,z};
	} 
	dfs1(1,0);
	dfs2(1,1,0);
	for(int i = 2; i <= n; i++){
		modify(i,dfw[i]);
	}
	for(int i = 1; i <= m; i++){
		int op,x,y;
		cin >> op >> x >> y;
		if(op == 1){
			if(x == ch) cw = y;
			else{
				if(f[e[x].u] == e[x].v){
					modify(dfn[e[x].u],y-e[x].w);
				}else{
					modify(dfn[e[x].v],y-e[x].w);
				}
				e[x].w = y;
			}
		}else{
			cout << min(ask(x,y),min(ask(x,cu)+ask(y,cv)+cw,ask(x,cv)+ask(y,cu)+cw)) << "\n";
		}
	}
	return 0;
}
