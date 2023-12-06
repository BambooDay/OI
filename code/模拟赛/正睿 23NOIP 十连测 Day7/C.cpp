#include <bits/stdc++.h>
//#define int long long
const int N = 2005;
const int mod = 1e9+7;
const int M = 1e5+10;

using namespace std;
int n,m,q;
struct sqare{
	int x1,y1,x2,y2;
}Node[M];
int ans_ma = 1,ans_cnt = 0;
int dis[N][N];
bool in[N][N];
void init(){
	memset(dis,1,sizeof dis);
	memset(in,1,sizeof in);
	memset(ava,0,sizeof ava);
	ans_ma = 1,ans_cnt = 0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= q; i++){
		sacnf("%d%d%d%d",&Node[i].x1, &Node[i].y1,&Node[i].x2,&Node[i].y2);
	}
}
void solve(){
	init();
	queue<int> q;
	
	for(int i =1;i <= n; i++){
		for(int j = 1; j<= m; j++){
			q.push({i,j});
		}
	}
	while(!q.empty()){
		int x = q.front().first,y = q.front().second;
		q.pop();
		in[x][y] = 0;
		int xx1
	}
}
signed main(){
	
	return 0;
}
