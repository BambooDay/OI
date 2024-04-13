#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
int n;
vector<int> e[N];
int ans = 2;
int cnt[N];
bool flag = 1;
int dfs(int pos, int fa){
	int siz = 1;
	for(int to : e[pos]){
		if(to == fa) continue;
		siz += dfs(to,pos); 
	}
	cnt[siz]++;
	return siz;
}
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}	
	dfs(1,0);
	for(int i = 2; i < n; i++){
		if(n%i) continue;
		int ret = 0;
		for(int j = i; j <= n; j += i) ret += cnt[j];
		if(ret >= n/i) ans++;
	}
	cout << ans;
	return 0;
}
