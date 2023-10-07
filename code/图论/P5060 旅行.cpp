#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e6+10;
const int M = 1e7+10;
const int INF = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m,p,A,B;
int h[N],ne[M],node[M];
ll val[M],idx;
void add(int u, int v, ll w){
	ne[++idx] = h[u];
	node[idx] = v;
	val[idx] = w;
	h[u] = idx;
}
struct Node{
	int id;
	ll w;
	Node () {}
	Node(int _id,ll _w):id(_id),w(_w){}
	bool operator < (const Node &node)const{
		return w > node.w;///////////
	} 
};
bool vis[N];
ll dis[N];
int fa[N];
priority_queue<Node> q;
void dijs(){
	dis[A] = 0;
	q.push(Node(A,0));
	while(!q.empty()){
		Node u = q.top();
		q.pop();
		if(u.id == B) return;
		if(vis[u.id]) continue;
		vis[u.id] = 1;
		for(int i = h[u.id]; i; i = ne[i]){
			int to = node[i];
			if(!vis[to] && dis[to] > dis[u.id] + val[i]){
				fa[to] = u.id;
				dis[to] = dis[u.id] + val[i];
				q.push(Node(to,dis[to]));
			}
		}
	}
}
int ans[N];
int len;
void print(int rt){
	if(rt==0) return ;
	if(rt%n!=0) ans[++len]=rt%n;
	else ans[++len]=n;
	print(fa[rt]);
}
signed main(){
	cin >> n >> m >> p>> A >> B;
	for(int i = 1;i <= m ;i++){
		int a, b ;
		ll c;
		cin >> a >> b >> c;
		for(int j = 0; j < p; j++){
			add(j * n + a,(j + c) % p * n + b, c);
		}
	}
	memset(dis,0x7f7f7f7f,sizeof dis);
	dijs();
	if(dis[B]==9187201950435737471) puts("jjc fails in travelling");
	else{
		cout << dis[B] << endl;
		print(B);
		for(int i = len; i > 1; i--){
			cout << ans[i] << "->";
		}
		cout << ans[1] << endl;
	}
	return 0;
}
