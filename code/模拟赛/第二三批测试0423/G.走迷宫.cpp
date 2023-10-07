#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m;
struct node{
	int x, y, step;
};
queue <node> q;
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};
char mp[50][50];

bool vis[50][50];
int main(){
	cin >> n >> m;
	for(int i = 1;i <=n; i++){
		scanf("%s",1+mp[i]);
	}
	node u;
	u.step = 1,u.x = 1,u.y =1 ;
	q.push(u);
	while(!q.empty()){
		node v = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = v.x+dirx[i],yy = v.y+diry[i];
			if(xx < 1 || xx > n || yy <1 || yy > n|| mp[xx][yy] == '#'|| vis[xx][yy]) continue;
			if(xx == n && yy == m){
				cout << v.step+1;
				return 0; 
			}
			vis[xx][yy] =1;
			node t;
			t.x = xx;
			t.y = yy;
			t.step = v.step+1;
			q.push(t);
		}
	}
	return 0;
}
