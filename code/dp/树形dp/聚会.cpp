#include <bits/stdc++.h>
const int N = 2e5+10;
using namespace std;
int n;
int val[N];
vector<int> e[N];
int ans = 0;
void dfs(int pos, int fa, int dis){
	ans += dis;
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs(to,pos,dis^val[to]);
	}
}
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> val[i];
	}	
	for(int i = 1; i < n; i++){
		int x,y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		ans = 0;
		dfs(i,0,val[i]);
		cout << ans << " ";
	}
	return 0;
}
