#include <bits/stdc++.h>
const int N = 2e5+10;
using namespace std;
int h[N],ne[N<<1],node[N<<1];
int idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int n, m;
int dfn[N],hson[N],dep[N],siz[N],cnt,top[N],fa[N];
void dfs1(int x, int f){
//	cout << f << endl;
	fa[x] = f;
	siz[x] = 1;
	for(int i = h[x];i;i = ne[i]){
		int to = node[i];
		if(to == f) continue;
		dep[to] = dep[x]+1;
		dfs1(to,x);
		siz[x] += siz[to];
		if(siz[to] > siz[hson[x]]) hson[x] = to;
	}
}

void dfs2(int x, int topf){
	top[x] = topf;
	dfn[x] = ++cnt;
	if(!hson[x]) return;
	dfs2(hson[x],topf);
	for(int i = h[x];i;i = ne[i]){
		int to = node[i];
		if(to == hson[x] || to == fa[x]) continue;
		dfs2(to,to);
	}
}

int tag[N << 2], sum[N << 2];
#define ls(fa) fa<<1
#define rs(fa) fa<<1|1
void push_up(int pos){
	sum[pos] = sum[ls(pos)] + sum[rs(pos)];
}
void push_down(int pos, int l , int r){
	int mid = (l+r) >> 1;
	tag[rs(pos)] = tag[ls(pos)] = tag[pos];
	if(tag[pos] == 1){
		sum[ls(pos)] = sum[rs(pos)] = 0;
	}else if(tag[pos] == 2){
		sum[ls(pos)] = mid-l+1,sum[rs(pos)] = r - mid;
	}
	tag[pos] = 0;
}
int ask(int pos, int l, int r, int x, int y){
	if(x <= l && y >=r) return sum[pos];
	int mid = (l+r) >> 1;
	int res = 0;
	if(tag[pos]) push_down(pos,l,r);
	if(x <= mid) res += ask(ls(pos),l,mid,x,y);
	if(y > mid) res += ask(rs(pos),mid+1,r,x,y);
	return res; 
}

void change(int pos, int l, int r, int x, int y, int z){
	if(x <= l && y >= r){
		tag[pos] = z;
		if(z == 1) sum[pos] = 0;
		else if(z == 2) sum[pos] = r-l+1;
		return;
	}
	int mid = (l+r) >> 1;
	if(tag[pos]) push_down(pos,l,r);
	if(x <= mid) change(ls(pos),l,mid,x,y,z);
	if(y > mid) change(rs(pos),mid+1,r,x,y,z);
	push_up(pos);
}


int qrange(int x, int y){
	int res = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		res += dfn[x] - dfn[top[x]]+1 - ask(1,1,n,dfn[top[x]],dfn[x]);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	res += dfn[x] - dfn[y] + 1 - ask(1,1,n,dfn[y],dfn[x]);
	return res;
}
void crange(int x, int y, int z){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		change(1,1,n,dfn[top[x]],dfn[x],z);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	change(1,1,n,dfn[y],dfn[x],z);
}
int qson(int pos){
	return ask(1,1,n,dfn[pos],dfn[pos]+siz[pos]-1);
}
void cson(int pos, int d){
	change(1,1,n,dfn[pos],dfn[pos]+siz[pos]-1,d);
}

int main(){
//	freopen("P2146_1.in","r",stdin);
	cin >> n;
//	cout << n <<endl;
	for(int x = 2; x <= n; x++){
		int y;
		cin >> y;
//		cout << y << " ";
		y++;
		add(y,x);
		add(x,y);
	}
	dfs1(1,0);
	dfs2(1,1);

	cin >> m;
//	cout << m;
	while(m--){
		string op;
		cin >> op;
		int x;
		cin >> x;
		x++;
		if(op == "install"){
			cout<< qrange(1,x) << endl;
			crange(1,x,2);
		}else{
			cout<< qson(x) << endl;
			cson(x,1);
		}
	}
	return 0;
}
