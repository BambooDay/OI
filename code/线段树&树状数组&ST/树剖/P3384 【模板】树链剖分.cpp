#include <bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,m,r,mod;
vector<int> e[N];

//-------------------------------------- 以下为线段树
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
int node[N<<2],add[N<<2];
int a[N],nw[N];
void push_up(int pos) {
	node[pos] = node[ls(pos)] + node[rs(pos)];
}
void build(int pos, int l, int r) {
	if(l == r) {
		node[pos] = nw[l] % mod;
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void push_down(int pos, int l, int r) {
	add[ls(pos)] += add[pos];
	add[ls(pos)] %= mod;
	add[rs(pos)] += add[pos];
	add[rs(pos)] %= mod;
	int mid = (l+r) >> 1;
	node[ls(pos)] += (mid-l+1)*add[pos];
	node[ls(pos)] %= mod;
	node[rs(pos)] += (r - mid) * add[pos];
	node[rs(pos)] %= mod;
	add[pos] = 0;
}
void update(int pos, int l, int r, int x, int y, int z) {
	if(x <= l && y >= r) {
		add[pos] += z;
		add[pos] %= mod;
		node[pos] += (r-l+1) * z;
		node[pos] %= mod;
		return;
	}
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	if(mid >= x) {
		update(ls(pos),l,mid,x,y,z);
	}
	if(mid < y) {
		update(rs(pos),mid+1,r,x,y,z);
	}
	push_up(pos);
}
int query(int pos,int l,int r, int x, int y) {
	if(x <= l && r<= y) {
		return node[pos];
	}
	int res = 0;
	push_down(pos,l,r);
	int mid = (l + r)  >> 1;
	if(mid >= x) {
		res += query(ls(pos),l,mid,x,y);
		res %= mod;
	}
	if(mid < y) {
		res += query(rs(pos),mid+1,r,x,y);
		res %= mod;
	}
	return res;
}
//---------------------------------以上为线段树
int top[N],siz[N],hson[N],dep[N],fa[N];
void dfs1(int pos, int f) {
	dep[pos] = dep[f]+1;
	fa[pos] = f;
	siz[pos] = 1;
	int son = -1;
	for(int to : e[pos]) {
		if(to == f) continue;
		dfs1(to,pos);
		siz[pos] += siz[to];
		if(siz[to] > son) son = siz[to],hson[pos] = to;
	}
}
int dfn[N],idx = 0;
void dfs2(int pos, int tf) {
	dfn[pos] = ++idx;
	nw[idx] = a[pos];
	top[pos] = tf;
	if(!hson[pos]) return;
	dfs2(hson[pos],tf);
	for(int to : e[pos]) {
		if(to == fa[pos] || to == hson[pos]) continue;
		dfs2(to,to);
	}
}
int ask_range(int x, int y) {
	int ans = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans +=query(1,1,n,dfn[top[x]],dfn[x]);
		ans %= mod;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y])swap(x,y);
	ans += query(1,1,n,dfn[x],dfn[y]);
	return ans % mod;
}

void upd_range(int x,int y,int k) {
	k %= mod;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x],k);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x,y);
	update(1,1,n,dfn[x],dfn[y],k);
}

int ask_son(int x) {
	return query(1,1,n,dfn[x],dfn[x]+siz[x]-1);
}

void upd_son(int x,int k) { //同上
	update(1,1,n,dfn[x],dfn[x]+siz[x]-1,k);
}


signed main() {
	cin >> n >> m >> r >> mod;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	while(m--) {
		int k,x,y,z;
		cin >> k;
		if(k == 1) {
			cin >> x >> y >> z;
			upd_range(x,y,z);
		} else if(k == 2) {
			cin >> x >> y;
			printf("%d\n",ask_range(x,y));
		} else if(k == 3) {
			cin >> x >> y;
			upd_son(x,y);
		} else {
			cin >> x;
			printf("%d\n",ask_son(x));
		}
	}
}
