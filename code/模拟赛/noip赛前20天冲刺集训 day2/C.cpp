#include <bits/stdc++.h>
const int N = 6e5+10;
const int M = 9e5+10;
using namespace std;
int n,m;
struct edge{
	int u,v;
}e[M];
int deg[N];
string ans;
int ans_cnt = -1;
void dfs(int dep, string s){
	if(dep > m){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(deg[i]) cnt++;
		}
		//if(s == "110"){
		//	cout << " mmm " << cnt << " " << ans_cnt << endl;
		//}
		if(cnt > ans_cnt){
			ans = s;
			ans_cnt = cnt;
		}else if(cnt == ans_cnt){
			ans = max(ans,s);
		}
		return;
	}
	deg[e[dep].u] ^= 1;
	deg[e[dep].v] ^= 1;
	dfs(dep+1,s + "1");
	deg[e[dep].v] ^= 1;
	deg[e[dep].u] ^= 1;	
	dfs(dep+1,s + "0");

}
int main(){
	cin >> n >> m;
	for(int i =1;i <= m; i++){
		cin >> e[i].u >> e[i].v;
		e[i].u++;
		e[i].v++;
	}
	dfs(1,"");
	cout << ans << endl;
	//cout << ans_cnt << endl;
	return 0;
}