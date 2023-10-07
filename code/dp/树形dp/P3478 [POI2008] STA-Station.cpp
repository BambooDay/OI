#include <bits/stdc++.h>
const int N = 1e6+10;
#define int long long
using namespace std;
int n;
vector<int> e[N];
int ans, id;
int dis[N];
int siz[N];
int dep[N];
void dfs1(int pos, int fa){
	siz[pos] = 1;
	dep[pos] = dep[fa] + 1;
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs1(to,pos);
		siz[pos] += siz[to];
//		dis[pos] += siz[to]; 
	}
}
void dfs2(int pos, int fa){
	for(int to : e[pos]){
		if(to == fa) continue;
		dis[to] = dis[pos] + n - 2*siz[to];
		dfs2(to,pos);
	}
}
signed main(){
	cin >> n;
	for(int i =1;i < n; i++){
		int u,v;
		cin >> u >>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	dfs1(1,0);
	for(int i =1; i <= n; i++){
		dis[1] += dep[i];
	}
	dfs2(1,0);
	for(int i = 1; i <= n; i++){
		if(dis[i] > ans){
			ans = dis[i];
			id = i;
		}
	}
	cout << id;
	return 0;
}
