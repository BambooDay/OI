#include <bits/stdc++.h>

using namespace std;
int n,p;
int siz[200];
int f[200][200];
vector<int> e[200];
void dp(int pos,int fa){
	siz[pos] = 1;
	f[pos][1] = e[pos].size()- !!fa;
	for(int to : e[pos]){
		if(to == fa) continue;
		dp(to,pos);
		siz[pos] += siz[to];
		for(int i = siz[pos];i >= 0; i--){
			for(int j = 1; j < i; j++){
				f[pos][i] = min(f[pos][i], f[pos][i-j] + f[to][j] - 1);
			}
		} 
	}
}
int main(){
	cin >> n >> p;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(f,0x3f,sizeof f);
	dp(1,0);
//	for(int i = 1; i <= n; i++) cout << f[i][1] <<" ";
	int ans = 1e18;
//	cout << f[1][p] << endl;
	for(int i = 1; i <= n; i++){
		ans = min(ans,f[i][p]+(i != 1));
	}
	cout << ans;
	return 0;
}
