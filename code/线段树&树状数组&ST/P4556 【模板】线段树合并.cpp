#include <bits/stdc++.h>
const int N = 1e5+10;
const int down = 1;
const int up = 1e5;
#define ls(pos) tr[pos].l
#define rs(pos) tr[pos].r
#define val(pos) tr[pos].val
using namespace std;
int n,m;
vector<int> e[N];
int dep[N],fa[N][20];
void dfs(int pos, int f){
	fa[pos][0] = f;
	dep[pos] = dep[f]+1;
	for(int i = 1; i <= 15; i++){
		fa[pos][i] = fa[fa[pos][i-1]][i-1];
	}
	for(int to : e[pos]){
		if(to == f) continue;
		dfs(to,pos);
	}
}
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 15; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 15; i >= 0; i--){
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}
struct Node{
	int l=0,r=0;
	int val = 0;
}tr[N*600];
int tot = 0,rt[N],ans[N];
void push_down(int pos){
	if(!ls(pos)) ls(pos) = ++tot;
	if(!rs(pos)) rs(pos) = ++tot;
}
void modify(int pos, int l, int r, int x, int y){
	if(l == r){
		val(pos) += y;
		return;
	}
	push_down(pos);
	int mid = (l+r)>>1;
	if(x <= mid) modify(ls(pos),l,mid,x,y);
	else modify(rs(pos),mid+1,r,x,y);
	val(pos) = max(val(ls(pos)),val(rs(pos)));
}
int merge(int u, int v){
	if(!u || !v) return u+v;
	ls(u) = merge(ls(u),ls(v));
	rs(u) = merge(rs(u),rs(v));
	if(!ls(u)&&!rs(u)){
		val(u) += val(v);
		return u;
	}
	val(u) = max(val(ls(u)),val(rs(u)));
	return u;
}
int ask(int pos,int l, int r){
	if(l == r) return l;
	int mid = (l+r)>>1;
	if(val(ls(pos)) >= val(rs(pos))) return ask(ls(pos),l,mid);
	else return ask(rs(pos),mid+1,r);
} 
void solve(int x, int f){
	for(int to : e[x]){
		if(to == f) continue;
		solve(to,x);
		rt[x] = merge(rt[x],rt[to]);
	}
	if(val(rt[x]) == 0) ans[x] = 0;
	else ans[x] = ask(rt[x],down,up);
}
int main(){
	cin >> n >> m;
	for(int i = 1;i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	dfs(1,0);
	for(int i = 1; i <= n; i++) rt[i] = ++tot;
	for(int i = 1; i <= m; i++){
		int x,y,z;
		cin >> x >> y >> z;
		int t = LCA(x,y);
//		cout << t << " ";
		modify(rt[x],down,up,z,1);
		modify(rt[y],down,up,z,1);
		modify(rt[t],down,up,z,-1);
		modify(rt[fa[t][0]],down,up,z,-1);
	}
	solve(1,0);
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
 	return 0;
}
