#include <bits/stdc++.h>
const int N = 16;
using namespace std;
struct Node{
	int x,y;
	Node(){}
	Node(int _x, int _y):x(_x),y(_y){} 
}node[N];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m,s;
int dis[N][N];
int d[505][505];
char mp[505][505];
int dp[1<<N][N];
string g[1<<N][N];
void bfs(Node f){
	memset(d,0,sizeof d);
	queue<Node> q;
	q.push(f);
	d[f.x][f.y] = 1;
	while(!q.empty()){
		Node u = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = u.x + dir[i][0],y = u.y + dir[i][1];
			if(x < 1 || y < 1 || x > n || y > m || mp[x][y] == '*' || d[x][y]) continue;
			d[x][y] = d[u.x][u.y]+1;
			q.push((Node){x,y}); 
		}
	}
}
int main(){
	cin >> n >> m >> s;
	for(int i = 1;i <= n; i++) scanf("%s",mp[i]+1);
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] >= 'A' && mp[i][j] <= 'Z'){
				node[mp[i][j] - 'A'+1] = (Node){i,j};
			}
		}
	} 
	for(int i =1 ;i <= s; i++){
		bfs(node[i]);
		for(int j = 1; j <= s; j++){
			dis[i][j] = d[node[j].x][node[j].y]-1;
		}
	}
	memset(dp,63,sizeof dp); 
	dp[1][1] = 0;
	g[1][1] = 'A';
	for(int i = 2; i < (1 << s); i++){
		if(!(i&1)) continue;
		for(int j = 1; j <= s; j++){
			if(i & (1 << (j-1)) == 0) continue;
			for(int k = 2; k <= s; k++){
				if(i & (1 << (k-1)) == 0 || j == k) continue;
				if(dp[i][k] > dp[i^(1 << (k-1))][j] + dis[j][k]){
					dp[i][k] = dp[i^(1 << (k-1))][j] + dis[j][k];
					g[i][k] = g[i^(1 << (k-1))][j] + char(k+'A'-1);
				}else if(dp[i][k] == dp[i^(1 << (k-1))][j] + dis[j][k] && g[i][k] > (g[i ^ (1 << (k - 1))][j] + (char)(k + 'A' - 1))){
					g[i][k] = (g[i ^ (1 << (k - 1))][j] + (char)(k + 'A' - 1));
				}
			}
		}
	}
	int t = (1 << s) -1;
	int mi = dp[t][2];
	string res = g[t][2];
	for(int i =3; i <= s; i++){
		if(mi > dp[t][i]){
			mi = dp[t][i];
			res = g[t][i];
		}else if(mi == dp[t][i] && res > g[t][i]) res = g[t][i];
	}
	cout << mi << endl << res;
	return 0;
}
