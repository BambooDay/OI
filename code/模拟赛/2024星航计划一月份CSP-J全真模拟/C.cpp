#include <bits/stdc++.h>
const int N = 805;

using namespace std;
char mp[N][N];
int n,s;
int dis[N][N];
queue<pair<int,int> > gz;
int xm,ym,xd,yd;
int dirx[4] = {0,1,0,-1};
int diry[4] = {1,0,-1,0};
void get_dis(){
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			cin >> mp[i][j];
			dis[i][j] = -1;
			if(mp[i][j] == 'M') xm = i,ym = j;
			if(mp[i][j] == 'D') xd = i,yd = j;
			if(mp[i][j] == 'H') dis[i][j] = 0,gz.push({i,j});
		}
	}
//	exit(gz.size());
	for(int i = 0; i <= n+1; i++) dis[0][i] = dis[i][0] = -1;
	while(!gz.empty()){
		int nx = gz.front().first,ny = gz.front().second;
		gz.pop();
		for(int i = 0; i < 4; i++){
			int xx = nx+dirx[i],yy = ny + diry[i];
			if(xx < 1 || xx > n || yy < 1 || yy > n || mp[xx][yy] == 'T' || mp[xx][yy] == 'D'||mp[xx][yy] == 'H' || (dis[xx][yy] != -1)) continue;
//			cout << xx << " 111 " << yy << endl;
			dis[xx][yy] = dis[nx][ny]+1;
			gz.push({xx,yy});
		} 
	}
//	dis[xm][ym] = 1e9;
}
queue<pair<int,int> > q;
bool in[N][N];
pair<int,int>  d[N][N];
void work(){
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= n; j++){
			d[i][j].first = -1;
		}
	}
//	for(int i = 0; i < 4; i++){
//		int xx = xd+dirx[i],yy = yd+diry[i];
//		if(dis[xx][yy] > 0){
//			q.push({xx,yy});
//			d[xx][yy] = {dis[xx][yy],2};
//			in[xx][yy] = 1;
//		}
//	}
	q.push({xd,yd});
	d[xd][yd] = {1e9,0};
	while(!q.empty()){
		int nx = q.front().first,ny = q.front().second;
		q.pop();
		in[nx][ny] = 0;
		if(nx == xm && ny == ym) continue;
		for(int i = 0; i < 4; i++){
			int xx = nx+dirx[i],yy = ny + diry[i];
			if(dis[xx][yy] == -1 ) continue; 
//			cout << xx << " 11 " << yy << endl;
			int nd = d[nx][ny].first,ns = d[nx][ny].second+1;
			if(dis[xx][yy] < d[nx][ny].first){
				nd = dis[xx][yy],ns = 1;
			}else if(ns > s){
				nd--,ns = 1;
			}
			if(nd > d[xx][yy].first||(nd == d[xx][yy].first && ns < d[xx][yy].second)){
				d[xx][yy] = {nd,ns};
				if(!in[xx][yy]){
					in[xx][yy] = 1;
					q.push({xx,yy});
				}
			}
		}
	}
}
int main(){
//	cout << -1;
	cin >> n >> s;
//	return s;
	get_dis();
//	for(int i = 1;i <= n; i++){
//		for(int j = 1;j <= n; j++){
//			cout << dis[i][j] << "       ";
//		}
//		cout << endl;
//	}
	work();
//	for(int i = 1;i <= n; i++){
//		for(int j = 1;j <= n; j++){
//			cout << d[i][j].first << "," << d[i][j].second << "       ";
//		}
//		cout << endl;
//	}
	cout << d[xm][ym].first-1;
	return 0;
} 
