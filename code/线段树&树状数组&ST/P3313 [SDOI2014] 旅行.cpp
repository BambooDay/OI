#include <bits/stdc++.h>
const int N  = 1e5+10;
using namespace std;

int n,m;

int dep[N],dfn[N],hson[N],top[N],siz[N],f[N],dfc = 0;
vector<int> e[N];
void dfs1(int pos, int fa){
	dep[pos] = dep[fa]+1;
	f[pos] = fa;
	siz[pos] = 1;
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs1(to,pos);
		siz[pos] += siz[to];
		if(siz[to] > siz[hson[pos]]) hson[pos] = to;
	}
}
void dfs2(int pos, int fa, int tp){
	dfn[pos] = ++dfc;
	top[pos] = tp;
	if(hson[pos]) dfs2(hson[pos],pos,tp);
	for(int to : e[pos]){
		if(to == fa || to == hson[pos]) continue;
		dfs2(to,pos,to);
	} 
}
struct Node{
	int l,r,sum,ma;
}tr[20000110];
int tot = 0;
#define ls(pos) tr[pos].l
#define rs(pos) tr[pos].r
#define ma(pos) tr[pos].ma
#define sum(pos) tr[pos].sum
void update(int &rt, int l, int r, int x, int y){
	if(!rt) rt = ++tot;
	ma(rt) = max(ma(rt),y);
	sum(rt) += y;
	if(l == r) return;
	int mid = (l+r)/2;
	if(x <= mid) update(ls(rt),l,mid,x,y);
	else update(rs(rt),mid+1,r,x,y); 
}
void del(int pos, int l, int r, int x){
	if(l == r){
		sum(pos) = 0;
		ma(pos) = 0;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) del(ls(pos),l,mid,x);
	else del(rs(pos),mid+1,r,x);
	sum(pos) = sum(ls(pos)) + sum(rs(pos));
	ma(pos) = max(ma(rs(pos)),ma(ls(pos)));
}
int query_sum(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return sum(pos);
	}
	int mid = (l+r) >> 1;
	int ans = 0;
	if(x <= mid) ans += query_sum(ls(pos),l,mid,x,y);
	if(mid < y) ans += query_sum(rs(pos),mid+1,r,x,y);
	return ans;
}
int query_max(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return ma(pos);
	}
	int mid = (l+r) >> 1;
	int ans = -1;
	if(x <= mid) ans = max(ans,query_max(ls(pos),l,mid,x,y));
	if(mid < y) ans = max(ans,query_max(rs(pos),mid+1,r,x,y));
	return ans;
}
int rt[N];

int ask_max(int x,int y, int kind){
	int ans = -1;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans = max(ans,query_max(rt[kind],1,n,dfn[top[x]],dfn[x]));
		x = f[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	ans = max(ans,query_max(rt[kind],1,n,dfn[y],dfn[x]));
	return ans;
}
int ask_sum(int x,int y, int kind){
	int ans = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		ans += query_sum(rt[kind],1,n,dfn[top[x]],dfn[x]);
		x = f[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	ans += query_sum(rt[kind],1,n,dfn[y],dfn[x]);
	return ans;
}
int w[N],kind[N];

int main(){
	cin >> n >> m;
	for(int i =1;i <= n; i++) cin >> w[i] >> kind[i];
	for(int i =1;i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i =1;i <= n; i++){
		update(rt[kind[i]],1,n,dfn[i],w[i]);
//	cout << 111 << endl;
	}
	while(m--){
		string op;
		int x,y;
		cin >> op >> x>>y;
		if(op[1] == 'C'){
			del(rt[kind[x]],1,n,dfn[x]);
			update(rt[y],1,n,dfn[x],w[x]);
			kind[x] = y;
		}
		if(op[1] == 'W'){
			del(rt[kind[x]],1,n,dfn[x]);
			update(rt[kind[x]],1,n,dfn[x],y);
			w[x] = y;			
		}
		if(op[1] == 'S'){
			cout << ask_sum(x,y,kind[x]) << endl;
		}
		if(op[1] == 'M'){
			cout<< ask_max(x,y,kind[x]) << endl;
		}
	}
	return 0;
}
