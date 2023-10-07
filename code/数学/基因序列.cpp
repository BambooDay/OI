#include <bits/stdc++.h>
#define int long long 
const int N = 1e5+10;
using namespace std;
vector<int> e[N];
int n;
int ans[N];
int val[N];
stack<int> pos[2000006];
vector<int> pr;
int pre[2000006];
void init(){
	for(int i = 2; i <= 2e6; i++){
		if(!pre[i]){
			pr.push_back(i);
		}
		for(int j : pr){
			if(j*i > 2e6) break;
			pre[i*j] = j;
			if(i %  j == 0) break;
		}
	}
}
void dfs(int cur){
	//cout << endl << cur<< ": ";
	int x = val[cur];
	ans[cur] = -1;
	while(pre[x]){
		if(!pos[pre[x]].empty()){
			if(pos[pre[x]].top() != cur)
				ans[cur] = max(ans[cur],pos[pre[x]].top());
		}
		pos[pre[x]].push(cur);
		//while(pre[x/pre[x]] == pre[x]) 
	//	x /= pre[x];
	//	cout << pre[x] << " ";
		x /= pre[x];
	}
	if(!pos[x].empty()){
		if(pos[x].top() != cur)
			ans[cur] = max(ans[cur],pos[x].top());
	} 
	pos[x].push(cur);
	for(int to : e[cur]) dfs(to);
	x = val[cur];
	while(pre[x]){	
		pos[pre[x]].pop();
		//while(pre[x/pre[x]] == pre[x]) 
		//x /= pre[x];
		x /= pre[x];
	}
	pos[x].pop();
}
int q;
signed main(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> val[i];
	}
	for(int i =1;i < n;i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
	}
	init();
	dfs(1);
	while(q--){
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}
	return 0;
}

/*
5 5
15 14 21 18 10
1 2
1 3
2 4
3 5
*/

