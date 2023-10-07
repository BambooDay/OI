#include <bits/stdc++.h>
const int N = 5005;

using namespace std;
int n;
vector<int> e[N];
int ans = 1e9;
int dep[N];

void bfs(int rt){
	dep[rt] = 1;
	queue<int> q;
	q.push(rt);
	int cnt = 1;
	bool vis[N] = {0};
	vis[rt] = 1;
	int res = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		res += dep[u]; 
		for(int v : e[u]){
			if(vis[v]) continue;
			vis[v] = 1;
			cnt++;
			dep[v] = dep[u]+1;
			q.push(v);
		}
	}	
	if(cnt == n){
		ans = min(ans,res);
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int k;
		cin >>k;
		for(int j = 1; j <= k; j++){
			int fa;
			cin >> fa;
			e[fa].push_back(i);
		}
	}	
	for(int i = 1;i <= n; i++){
		bfs(i);
	} 
	cout << ans;
	return 0;
}
