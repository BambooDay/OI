#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
int mp[60][60];
bool sv[60][60],ev[60][60];
int ex,ey,sx,sy;
ll ans = INF;
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
int nx,ny;
void sdfs(int x, int y){
	ans = min(ans,1ll*(x-nx)*(x-nx) + 1ll*(y-ny)*(y-ny));
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],yy = y + dy[i];
		if(xx > n || xx < 1 || yy > n || yy < 1 || mp[xx][yy]|| sv[xx][yy]){
			continue;
		}
		sv[xx][yy] = 1;
		sdfs(xx,yy);
	} 
}
void edfs(int x, int y){
	nx = x;
	ny = y;
	sdfs(sx,sy);
	for(int i = 0; i < 4; i++){
		int xx = x + dx[i],yy = y + dy[i];
		if(xx > n || xx < 1 || yy > n || yy < 1 || mp[xx][yy]|| ev[xx][yy]){
			continue;
		}
		memset(sv,0,sizeof sv);
		ev[xx][yy] = 1;
		edfs(xx,yy);
	}
}
int main(){
	cin >> n;
	cin >> sx >> sy >> ex >> ey;
	for(int i =1;i <= n; i++){
		for(int j =1 ; j <= n; j++){
			char c;
			cin >> c;
			mp[i][j] = c-'0';
		}
	}

	edfs(ex,ey);
	cout << ans;
	return 0;
}
