#include <bits/stdc++.h>
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
#define mid ((l+r)>>1) 
const int N = 1e5+10;

using namespace std;
int Node[N<<2];
void push_up(int pos){
	Node[pos] = Node[ls(pos)]+Node[rs(pos)];
}
void modify(int pos,int l, int r, int x, int y){
	if(l == r){
		Node[pos] += y;
		return;
	}
	if(x <= mid) modify(ls(pos),l,mid,x,y);
	else modify(rs(pos),mid+1,r,x,y);
	push_up(pos);
}
int query(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y) return Node[pos];
	int ans = 0;
	if(mid >= x) ans += query(ls(pos),l,mid,x,y);
	if(mid < y) ans += query(rs(pos),mid+1,r,x,y);
	return ans;
}

int n;
vector<int> e[N];
int dfn[N],dfc = 0,hson[N],top[N],fa[N],siz[N];
void dfs1(int pos, int f){
	fa[pos] = f;
	siz[pos] = 1;
	for(int to : e[pos]){
		if(to == f) continue;
		dfs1(to,pos);
		siz[pos] += siz[to];
		if(siz[to] >= siz[hson[pos]]) hson[pos] = to;
	}
}
void dfs2(int pos, int tp){
	dfn[pos] = ++dfc;
	top[pos] = tp;
	if(hson[pos]) dfs2(hson[pos],tp);
	for(int to : e[pos]){
		if(to == fa[pos] || to == hson[pos]) continue;
		dfs2(to,to);
	}
}
int ask(int pos){
	int ans = 0;
	while(pos){
		ans += query(1,1,n,dfn[top[pos]],dfn[pos]);
		pos = fa[top[pos]];
	}
	return ans;
}
signed main(){
//	freopen("P2982_2.in","r",stdin);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x,y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i = 1; i <= n; i++){
		int p;
		cin >> p;
		cout << ask(p) << endl;
		modify(1,1,n,dfn[p],1);
	}
	return 0;
}
