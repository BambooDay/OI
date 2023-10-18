#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n;
vector<int> e[N];
int siz[N],dep[N];
int ans[N];
void dfs(int pos, int fa){
	siz[pos] = 1;
	dep[pos] = dep[fa]+1;
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs(to,pos);
		siz[pos] += siz[to];
	}
	ans[pos] = n-siz[pos]+1;
}
int main(){
	freopen("dfs.in","r",stdin);
	freopen("dfs.out","w",stdout);
	cin >> n;
	for(int i =1;i < n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int i =1;i <= n; i++){
		printf("%d %d\n",dep[i],ans[i]);
		//cout << dep[i] << " " << ans[i] << endl;
	}
	return 0;
}