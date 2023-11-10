#include<bits/stdc++.h>
const int N = 2e5+10;
using namespace std;

int n,m,in[N],q[N];
vector<int> e[N];
vector<int> ans;
bool topo(){
	int cnt = 0;
	queue<int> q;
	for(int i = 1; i <= n; i++)	if(!in[i])	q.push(i);
	while(!q.empty()) {
		cnt++;
		int now = q.front();
		q.pop();
		for(int i : e[now]) {
			in[i]--;
			if(!in[i]) {
				q.push(i);
				ans.push_back(i);
			}
		}
	}
	return cnt == n;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u,v;
		cin >> u >> v;
		e[v].push_back(u);
		in[u]++;
	}
	if(!topo())	puts("-1");
	else {
		cout << ans.size() << endl;
		for(auto now:ans) cout << now << " 1\n";
	}
	return 0;
}

