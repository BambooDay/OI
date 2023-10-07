#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
vector <int> e[N];
int n;
int siz[N],cnt[N];
int pos;
void get_center(int x, int fa){
	cnt[x] = 1,siz[x] = 0;
	for(auto to : e[x]){
		if(to == fa) continue;
		get_center(to,x);
		cnt[x] += cnt[to];
		siz[x] = max(cnt[to],siz[x]);
	}
	siz[x] = max(siz[x],n - cnt[x]);
	if(siz[x] == siz[pos] && x < pos) pos = x;
	if(siz[x] < siz[pos]) pos = x;
}
int sum = 0;
void dfs(int x, int fa,int dis){
	sum += dis;
	for(auto to : e[x]){
		if(to == fa) continue;
		dfs(to,x,dis + 1);
	}
}
int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	siz[0] = INF;
	get_center(1,0);
	cout << pos << " ";
	dfs(pos,0,0);
	cout << sum;
	return 0;
}
