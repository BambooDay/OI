#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int fa[N];
int n,m;
int cnt = 1;
int main(){
	freopen("contest.in","r",stdin);
	freopen("contest.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++) fa[i] = cnt;
	for(int i = 1;i <= m; i++){
		int k;
		cin >> k;
		cnt = max(cnt,k);
		map<int,bool> m;
		for(int j = 1; j <= k; j++){
			int x;
			cin >> x;
			//if(m.count(fa[x])) fa[x] = ++cnt;
			//m[fa[x]] = 1;
		}
	}
	cout << cnt << endl;
	return 0;
}
/*
5 3
3 1 2 3
3 3 4 5
3 2 3 4

3
*/