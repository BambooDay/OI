#include <bits/stdc++.h>
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
bool mp[200][200];
int n, m;
int sum = 0,res = -INF;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int f(int x, int y){
	int cnt = 0;
	queue <pair<int,int> > q;
	q.push(make_pair(x,y));
	while(!q.empty()){
		int a = q.front().first,b = q.front().second;
		mp[a][b] = 1;
		q.pop();
		cnt++;
		for(int i = 0; i < 4; i++){
			int xx = a+dx[i],yy = b+dy[i];
			if(xx&&yy&&xx<m*2&&yy<n*2){
				if(!mp[xx][yy]){
					mp[xx][yy] = 1;
					xx+=dx[i],yy+=dy[i];
					q.push(make_pair(xx,yy));
				}
			}
		}
	}
	return cnt;
}
int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin >> m >> n;
	for(int i = 1; i < m*2; i+=2){
		for(int j = 1; j < n*2; j+=2){
			int p;
			cin >> p;
			if(p >= 8){ // south
				mp[i+1][j] = 1;
				p -= 8;
			} 
			if(p >= 4){//east
				mp[i][j+1] = 1;
				p -= 4;
			}
			if(p >= 2){//north
				mp[i-1][j] = 1;
				p-=2;
			}
			if(p >= 1){//west
				mp[i][j-1] = 1;
				p -= 1;
			}
		}
	}
	for(int i = 1; i < m*2; i+=2){
		for(int j = 1; j < n*2; j+=2){
			if(!mp[i][j]){
				sum++;
				res = max(res,f(i,j));
			}
			
		}
	}
	cout << sum << endl << res;
	return 0;
}

