#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
int dir[110][20];
struct Node{
	int s, step;
};
bool vis[1000010];

int bfs() {
	int ss;
	queue<Node> q;
	q.push( (Node) {(1 << n) - 1, 0});
	vis[(1 << n) - 1] = true;
	while (!q.empty()) {
		Node u = q.front();
		q.pop();
		if (u.s == 0) {
			return u.step;
		}
		for (int i = 1; i <= m; i++) {
			ss = u.s;
			for (int j = 1; j <= n; j++){
				if ( dir[i][j] == 1 && (ss & (1 << j - 1)) ){
					ss ^= (1 << j - 1);
				}else if ( dir[i][j] == -1 && !(ss & (1 << j - 1)) ){
					ss |= (1 << j - 1);
				} 
			}

			if (!vis[ss]) { 
				q.push( (Node){ss, u.step + 1});
				vis[ss] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> dir[i][j]; 

	cout << bfs();
	return 0;
}
