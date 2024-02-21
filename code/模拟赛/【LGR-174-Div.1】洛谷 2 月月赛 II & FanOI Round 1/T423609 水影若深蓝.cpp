#include <bits/stdc++.h>
const int N = 3e5+10;

using namespace std;
int n,m;
int fa[N];
int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
int cnt;
vector<int> vec[N];
bool vis[N];
map<int,int> mp;
void init(){
	cin >> n >> m;
	cnt = 0;
	mp.clear();
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		vec[i].clear();
		vis[i] = 0;
	} 
}

void solve(){
	init();
	for(int i = 1; i <= m; i++){
		int x,y;
		cin >> x >> y;
		fa[find(x)] = find(y);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[find(i)]){
			vis[find(i)] = 1;
			cnt++;
			vec[cnt].push_back(i);
			mp[find(i)] = cnt;
		}else vec[mp[find(i)]].push_back(i);
	}
	if(cnt == 1){
		puts("No");
		return;
	}
	puts("Yes");
	cout << vec[1][0] << " " << vec[2][0] << "\n";
	for(int i = 1; i < vec[1].size(); i++) cout << vec[2][0] << " " << vec[1][i] << '\n';
	for(int i = 1; i < vec[2].size(); i++) cout << vec[1][0] << " " << vec[2][i] << '\n';
	 
	for(int i = 3; i <= cnt; i++){
		for(int j : vec[i]){
			cout << vec[i-1][0] << " " << j << '\n'; 
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
