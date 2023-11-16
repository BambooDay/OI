#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
char bg;
struct E {
	int v,w,nxt;
} e[N<<2];

int n,m,h[N],cnt,u,v,w,d1[N],dn[N],id[N],st[N],o,L[N],R[N],t[N<<2],res[N];

bool I[N<<2];
void add(int u,int v,int w) {
	e[++cnt]=(E) {v,w,h[u]},h[u]=cnt;
}
bool vis[N];
void dij(int x, int d[],int f[]) {
	priority_queue<pair<int,int> > q;
	for(int i=1; i<=n; ++i) d[i]=2e9,vis[i] = 0;
	d[x]=0;
	q.push({0,x});
	while(!q.empty()) {
		u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u]; i; i = e[i].nxt) {
			v = e[i].v;
			if(d[v]>e[i].w+d[u]){
//				f[v] = u;
				d[v] = e[i].w+d[u],q.push({-d[v],v});
			}
		}
	}
}
void bfs(int x,int*d,int*f){
	queue<int> Q;
	Q.push(st[x]),f[st[x]]=x;
	while(!Q.empty()){
		u=Q.front(),Q.pop();
		for(int i=h[u];i;i=e[i].nxt){
			v=e[i].v;
			if(!id[v]&&!f[v]&&d[u]+e[i].w==d[v])f[v]=x,Q.push(v);
            //若不在最短路上、没有被访问过、且u在1->v上，就搜索v
		}
	}
}//bfs求L,R
#define ls(fa) fa<<1
#define rs(fa) fa<<1|1
int node[N<<2];
void build(int pos,int l,int r){
    node[pos] = 1e9; 
	if(l == r) return; 
	int mid = (l+r)>>1;
    build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
}
void update(int pos,int l,int r,int x,int y,int w){
    if(x<=l&&r<=y){
    	node[pos] = min(node[pos],w);
	}else{
        int mid = (l+r)>>1;
        if(x <= mid) update(ls(pos),l,mid,x,y,w);
        if(y > mid) update(rs(pos),mid+1,r,x,y,w);
    }
}
int query(int pos,int l,int r,int p){
    if(l == r) return node[pos]; 
	int mid = (l+r)>>1;
    if(p <= mid) return min(node[pos],query(ls(pos),l,mid,p));
    else return min(node[pos],query(rs(pos),mid+1,r,p));
}
char ed;
int main() {
//	cout << (&bg-&ed)/1048576.0 << endl;
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	dij(1,d1,L);
	dij(n,dn,R);
	u = 1;
	while(u<n) {
		st[++o]=u,id[u]=o;
//		L[o] = o,R[o] = o;
		for(int i=h[u]; i; i=e[i].nxt) {
			v=e[i].v;
			if(dn[v]+e[i].w==dn[u]) {
				I[i]=1,u=v;
				break;
			}
		}
	}
	st[++o]=n,id[n]=o;
//	L[o] = o,R[o] = o;
	for(int i=1; i<=o; ++i)bfs(i,d1,L),bfs(i,dn,R);
	--o;
	build(1,1,o);
	for(u=1; u<=n; ++u)
		for(int i=h[u]; i; i=e[i].nxt) {
			v=e[i].v;
			if(!I[i]&&L[u]<R[v]) update(1,1,o,L[u],R[v]-1,d1[u]+e[i].w+dn[v]);
		}
	u=0,v=0;
	for(int i=1; i<=o; ++i) {
		res[i] = query(1,1,o,i);
		if(u<res[i])u=res[i],v=1;
		else if(u==res[i])++v;
	}
	if(u==d1[n])v=m;
	printf("%d %d\n",u,v);
	return 0;
}

