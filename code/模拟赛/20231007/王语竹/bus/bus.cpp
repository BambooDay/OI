#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 5e5+10;

using namespace std;
struct edge{
	int node,ne,id,num,g;
}e[M];
int h[N],idx;
void add(int u, int v, int id,int num,int g){
	e[++idx] = {v,h[u],id,num,g};
	h[u] = idx;
} 
int n,p,t;
struct Node{
	int u, id, d;
	friend operator <(Node a, Node b){
		if(a.d != b.d) return a.d > b.d;
		if(a.u != b.u) return a.u > b.u;
		return a.id > b.id; 
	}
};
int get(int now, int g, int num){//return k*g+num-now
	if(now <= num) return num - now;
//	now -= num;
	return (((now-num) / g + !!((now-num) % g)) * g+num - now);
}
long long dis[N];
bool vis[N];
void dij(){
	fill(dis,dis+5+n,1e18);
	dis[1] = 0;
	priority_queue<Node> q;
	for(int i = h[1]; i; i = e[i].ne){
		q.push({1,e[i].id,0});
	}
	while(!q.empty()){
		Node now = q.top();
		q.pop();
		int u = now.u,id = now.id,d = now.d;
//		cout << "u: " << u << " id: " << id << " d: " << d <<":" << endl; ;
		if(d > dis[u]+t) continue;
		for(int i = h[u];i; i = e[i].ne){
			if(e[i].id != id) d += t;
			int tmp = get(d,e[i].g,e[i].num)+1;
			int v = e[i].node;
//			cout << "v: " << v << " tmp-1: " << tmp-1 << " dis: " << dis[v]  << " id: " << e[i].id << " num: " << e[i].num << " g: " << e[i].g << endl; 
//			exit(0);
			if(dis[v] > d + tmp){
				dis[v] = d + tmp;
				q.push({v,e[i].id,dis[v]});
			}
			if(e[i].id != id) d -= t;
		}
	}
}
int s[200005];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> p >> t;
	for(int i = 1; i <= p; i++){
		int m,g,a,b,s0;
		cin >> m >> g;
		m++;
		for(int j = 1; j <= m; j++) cin >> s[j];
		for(int j = 1; j < m; j++){
			add(s[j],s[j+1],i,j-1,g); 
		}
		for(int j = m; j > 1; j--){
			add(s[j],s[j-1],i,2*(m-1)-j+1,g);
		} 
	}	
	
	dij();
	cout << dis[n];
	return 0;
}


