#include <bits/stdc++.h>
#define int long long
const int mod = 1000000009;

using namespace std;
int mp[120][120];
int dirx1[4] = {1,-1,0,0},diry1[4] = {0,0,1,-1};//dirx2[4] = {0,0,-1,1},diry2[4]={-1,1,0,0};
int res = 1e9,cnt = 0;
bool v[120][120];
int n;
void dfs(int x, int y,int sum){
	if(x +y-1 == n){
		cout << x << " " << y << endl;
		sum -= mp[x][y];
//		cout <<sum << endl;
		if(sum < res){
			res = sum;
			cnt = 1;
		}else if(sum == res){
			cnt++;
			cnt %= mod;
//			if(cnt >= mod) cnt-= mod;
		}
		return;
	}
	if(sum > res) return;
	for(int i = 0; i < 4; i++){
		int xx = x+dirx1[i],yy = y+diry1[i];
		if(v[xx][yy] || (n-yy+1) < xx || xx >n || xx <= 0 || yy > n || yy <= 0) continue;
//		cout << xx << " " << yy << endl;
		v[xx][yy] = 1;
		dfs(xx,yy,sum+mp[xx][yy]+mp[n-yy+1][n-xx+1]);
		v[xx][yy] = 0;
	}
}
void solve(){
	res = 1e18;
	cnt = 1;
	memset(v,0,sizeof v);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> mp[i][j];
//			v[i][j] = 0;
		}
	}
	dfs(1,1,mp[1][1]+mp[n][n]);
	cout << cnt << endl;
}
signed main(){
	while(cin >> n && n !=0){
		solve();
	}
	return 0;
}
