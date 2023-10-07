#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
const int N = 1e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
vector<pair<int ,int> > e[N];
int n;
/*int dis[N];
void dfs(int pos,int fa){
	for(auto to : e[pos]){
		if(to == fa) continue;
		dis[to] = dis[pos] + 1;
		dfs(to,pos);
	}
}
int work(int node){
	dfs(node,0);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dis[i] > dis[ans]) ans = i;
	}
	return ans;
}*/
int ans = 0;
int dp(int pos,int fa){
	int d1 = 0, d2 = 0;
	for(auto to : e[pos]){
		if(to.first == fa) continue;
		int d = dp(to.first,pos) + to.second;
		if(d > d1) d2 = d1,d1 = d;
		else if(d > d2) d2 = d;
	}
	ans = max(ans, d1 + d2);
	return d1;
}
signed main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v,w;
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w)); 
	}
	/*int s1 = work(1);
	dis[s1] = 0;
	int s2 = work(s1);
	cout << dis[s2] << endl;*/
	dp(1,0);
	cout << (ans+21) * ans/ 2 << endl;
	return 0;
}
