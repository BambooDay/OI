#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int dirx[4] = {0,1,0,-1};
int diry[4] = {1,0,-1,0};
void solve(){
	int n;
	cin >> n;
	bool mp[200][200];
	for(int i = 1;i <= n; i++){
		for(int j =1;j <= n; j++){
			char ch;
			cin >> ch;
			if(ch == '#') mp[i][j] = 1;
		}
	}
	int xa,xb,ya,yb;
	cin >> xa >> ya >> xb >> yb;
	if(mp[xa][ya] || mp[xb][yb]){
		cout << "NO"<< endl;
		return;
	}
	queue<pair<int,int> > q;
	q.push(make_pair(xa,ya));
	mp[xa][ya] = 1;
	while(!q.empty()){
		pair<int,int> t = q.front();
		if(t.first == xb && t.second == yb){
			cout << "YES" << endl;
			return;
		}
		for(int i = 0; i < 4; i++){
			int xx = t.first+dirx[i],yy = t.second+diry[i];
			if(xx > 0 && xx <= n && yy > 0 && yy <= n && !mp[xx][yy]){
				mp[xx][yy] = 1;
				q.push(make_pair(xx,yy));
			}
		}
	}
	cout << "NO" << endl;
	return;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
