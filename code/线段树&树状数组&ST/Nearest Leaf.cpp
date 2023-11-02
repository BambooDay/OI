#include <bits/stdc++.h>
#define int long long
const int N = 5e5+10;
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)

using namespace std;
int node[N<<2],add[N<<2];
int a[N];
int n,m;
void push_up(int pos){
	node[pos] = min(node[ls],node[rs]);
	
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(pos);
}
void push_down(int pos, int l, int r){
	add[ls] += add[pos];
	add[rs] += add[pos];
	node[ls] += add[pos];
	node[rs] += add[pos];
	add[pos] = 0; 
//	push_up(pos);//11111111
}
void update(int pos, int l, int r, int x, int y, int z){
//	cout << pos << endl; 
	if(x <= l && y >= r){
		add[pos] += z;
		node[pos] += z;
		return;
	}
	push_down(pos,l,r);
	if(mid >= x){
		update(ls,l,mid,x,y,z);
	}
	if(mid < y){
		update(rs,mid+1,r,x,y,z);
	}
	push_up(pos);
}
int query(int pos,int l,int r, int x, int y){
	if(x <= l && r<= y){
		return node[pos];
	}
	int res = 0;
	push_down(pos,l,r);
	if(mid >= x){
		res += query(ls,l,mid,x,y);
	}
	if(mid < y){
		res += query(rs,mid+1,r,x,y);
	}
	return res;
}

int h[N],no[N],ne[N],val[N],idx;
void ad(int u,int v, int w){
	no[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w; 
}
int siz[N];
int dis[N];
void dfs1(int pos){
	siz[pos] = pos;
	for(int i = h[pos]; i; i = ne[i]){
		int to = no[i];
		int w = val[i];
		dis[to] = dis[pos] + w;
		dfs1(to);
		siz[pos] = max(siz[pos],siz[to]);
	}
	if(siz[pos] == pos) a[pos] = dis[pos];
	else a[pos] = 1e18;
}
vector<int> q[N];
int L[N],R[N],ans[N];
void dfs2(int pos){
	for(int i : q[pos]){
		ans[i] = query(1,1,n,L[i],R[i]);
	}
	for(int i = h[pos]; i; i = ne[i]){
		int to = no[i],w = val[i];
		update(1,1,n,1,n,w);
		update(1,1,n,pos,siz[pos],-w-w);
		dfs2(to);
		update(1,1,n,1,n,-w);
		update(1,1,n,pos,siz[pos],w+w);
		
	}
}
signed main(){
	cin >> n >> m;
	for(int i = 2; i <= n; i++){
		int x,y;
		cin >> x >> y;
		ad(x,i,y);
	}
	dfs1(1);
	build(1,1,n);
	for(int i = 1;i <= m; i++){
		int x;
		cin >> x;
		q[x].push_back(i);
		cin >> L[i] >> R[i]; 
	}
	dfs2(1);
	for(int i = 1; i <= m; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
