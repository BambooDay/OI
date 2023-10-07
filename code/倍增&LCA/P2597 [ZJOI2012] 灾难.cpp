#include <bits/stdc++.h>
const int N = 1e5+10; 
using namespace std;
int n, ans;
int h[N],ne[N<<2],node[N<<2],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int h1[N],ne1[N<<2],node1[N<<2],idx1 = 0;
void add1(int u, int v){
	node1[++idx1] = v;
	ne1[idx1] = h1[u];
	h1[u] = idx1;
}

int in[N], fa[N][30],dad[N],siz[N],dep[N];
void dfs(int pos){
	siz[pos] = 1;
	for(int i = h1[pos];i;i = ne1[i]){
		int to = node1[i];
		dfs(to);
		siz[pos] += siz[to];
	}
}
int LCA(int x, int y){
	if(x == y){
		return x;
	}
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 18; i >= 0; i--){
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 18; i >= 0; i--){
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y =fa[y][i];
	}
	return fa[x][0];
}

int main(){
	cin >> n;
	for(int i = 1; i < N; i++){
		dad[i] = -1;
	} 
	for(int i = 1;i <= n; i++){
		int x;
		while(cin >> x && x){
			add(x,i);
			in[i] ++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!in[i]){
			q.push(i);
			dad[i] = 0;
		} 
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		add1(dad[x],x);
		fa[x][0] = dad[x];
		dep[x] = dep[dad[x]] + 1;
		for(int i = 1; i <= 18; i++) fa[x][i] = fa[fa[x][i-1]][i-1];
		for(int i = h[x];i;i = ne[i]){
			int to = node[i];
			if(dad[to] == -1) dad[to] = x;
			else dad[to] = LCA(dad[to],x);
			if(--in[to] == 0) q.push(to);
		}
	}
	dfs(0);
	for(int i = 1;i <= n; i++){
		cout << siz[i]-1 << endl;
	}
	return 0;
}
