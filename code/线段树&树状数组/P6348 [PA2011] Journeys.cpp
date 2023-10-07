#include <bits/stdc++.h>
const int N = 6e6+10;
const int M = 1e7+10;
using namespace std;
int h[N], ne[M],node[M],val[M],idx = 0;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int ls[N],rs[N];
int cnt;
void buildin(int &pos, int l, int r){
	if(l == r){
		pos = l;
		return;
	}
	pos = ++cnt;
	int mid = (l+r) >> 1;
	buildin(ls[pos],l,mid);
	buildin(rs[pos],mid+1,r);
	add(ls[pos],pos,0);
	add(rs[pos],pos,0);
}
void buildout(int &pos, int l, int r){
	if(l == r){
		pos = l;
		return;
	}
	pos = ++cnt; 
	int mid = (l+r) >> 1;
	buildout(ls[pos],l,mid);
	buildout(rs[pos],mid+1,r);
	add(pos,ls[pos],0);
	add(pos,rs[pos],0);
}
void update(int pos, int l, int r, int x, int y, int u, int type){
	if(x <= l && r <= y){
		type == 2? add(u,pos,1) : add(pos,u,1);
		return;
	}
	int mid = (l+r) >> 1;
	if(x <=mid){
		update(ls[pos],l,mid,x,y,u,type);
	}
	if(y > mid){
		update(rs[pos],mid+1,r,x,y,u,type);
	}
}
int dis[N];
bool v[N];
int n, m, p;
void dij(){
	priority_queue<pair<int,int> > q;
	dis[p] = 0;
	q.push(make_pair(dis[p],p));
	while(!q.empty()){
		int t = q.top().second;
		q.pop();
		if(v[t]) continue;
		v[t] = 1;
		for(int i = h[t]; i; i = ne[i]){
			int to = node[i];
			if(dis[to] > dis[t] + val[i]){
				dis[to] = dis[t] + val[i];
				q.push(make_pair(-dis[to],to));
			}
		}
	}
}
int rtout,rtin;
int main(){
	cin >> n >> m >> p;
	cnt = n;
	buildout(rtout,1,n);
	buildin(rtin,1,n);
	while(m--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		update(rtin,1,n,a,b,++cnt,3);
		update(rtout,1,n,c,d,cnt,2);
		update(rtin,1,n,c,d,++cnt,3);
		update(rtout,1,n,a,b,cnt,2);
	}
	memset(dis,0x3f,sizeof(dis));
	dij();
	for(int i = 1; i <= n; i++){
		if(dis[i] == 0x3f3f3f3f){
			cout << "-1" << endl;
		}else
			cout << dis[i] / 2 << endl;
	}
	return 0;
} 
