#include <bits/stdc++.h>
const int N = 3005;

using namespace std;
int n,m;
int ans_mi = 1e9,ans;
int dis[N][N];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= n; j++){
			dis[i][j] = 1e8;
		} 
	}
	for(int i = 1;i <= m; i++){
		int x,y;
		cin >> x >> y;
		dis[x][y] = dis[y][x] = 1;
	}
	
	for(int k = 1;k <= n; k++){
		for(int i = 1; i <= n; i++){
			if(k == i) continue;
			for(int j  = 1; j <= n; j++){
				if(i == j) continue;
				int t = dis[i][j] + dis[i][k] + dis[k][j];
//				cout << t << " ";
				if(t < ans_mi) ans_mi = t,ans = 1;
				else if(ans_mi == t) ans++;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	

	cout << ans/6;
	return 0;
}
