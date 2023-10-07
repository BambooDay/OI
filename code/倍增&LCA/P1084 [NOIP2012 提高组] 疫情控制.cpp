#include <bits/stdc++.h>
#define int long long
#define LL int
const int N = 5e4+10;
using namespace std;
int n, m;
int h[N],ne[N<<1],node[N<<1],idx = 0;
int val[N<<1];
void add(int u, int v,int w){
	node[++idx] = v;
	ne[idx] = h[u];
	val[idx] = w;
	h[u] = idx;
}
int fa[N][20],army[N];
int dis[N][20];
void dfs(int x, int f, int w){
	fa[x][0] = f,dis[x][0] = w;
	for(int i = 1;i <= 17; i++){
		fa[x][i] = fa[fa[x][i-1]][i-1];
		dis[x][i] = dis[x][i-1] + dis[fa[x][i-1]][i-1]; 
	}
	for(int i = h[x];i;i = ne[i]){
		if(node[i] != f){
			dfs(node[i],x,val[i]);
		}
	}	
}
struct Node{
	int rest;
	int id;
}a[N],b[N];
bool cmp(Node x, Node y){
	return x.rest > y.rest;
}
bool vis[N],used[N];
int restbj[N],restmin[N];
int nb,na;
bool find(int x, int last){
	int bj = 1,bbj = 0;
	if(vis[x]) return 1;
	for(int i = h[x];i;i = ne[i]){
		if(node[i] == last) continue;
		bbj = 1;
		if(!find(node[i],x)){
			bj = 0;
			if(x == 1) b[++nb].id = node[i],b[nb].rest = val[i];
			else return 0;
		}
	}
	if(!bbj) return 0;
	return bj;
}

bool check(int tim){
	na = nb = 0;
	for(int i = 1;i <= n; i++){
		vis[i] = restbj[i] = 0;
	}
	for(int i= 1;i <= m; i++){
		used[i] = 0;
	}
	for(int i = 1;i <= m; i++){
		int x = army[i],num = 0;

		for(int j = 17; j >= 0; j--){
			if(fa[x][j] > 1 && num + dis[x][j] <= tim){
				num += dis[x][j],x = fa[x][j];
			}
		}
		if(fa[x][0] == 1 && num + dis[x][0] <= tim){
			a[++na].rest = tim - num - dis[x][0],a[na].id = i;
			if(!restbj[x] || a[na].rest < restmin[x]){
				restmin[x] = a[na].rest,restbj[x] = i;
			}
		}else vis[x] = 1;
	}
	if(find(1,0)) return 1;
	sort(a+1,a+1+na,cmp);
	sort(b+1,b+1+nb,cmp);
	int now = 1;
	used[0] = 1;
	for(int i = 1; i <= nb; i++){
		if(!used[restbj[b[i].id]]){
			used[restbj[b[i].id]] = 1;
			continue;
		}
		while(now <= na&&(used[a[now].id] || a[now].rest < b[i].rest)) ++ now;
		if(now > na) return 0;
		used[a[now].id] = 1;
	}
	return 1;
}

signed main(){
	cin >> n;
	for(int i = 1; i < n;i ++){
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0,0);
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> army[i];
	} 
	int l = 0, r = 500000,ans = -1;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << ans;
	return 0;
}
