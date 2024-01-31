#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,m,r,c;
int cnt;
map<int,bool> mp;
void solve(){
	mp.clear(); cnt = 0;
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		mp[x] = 1;
	}	
	for(int i =1;i <= m; i++){
		int x;
		cin >> x;
		if(mp.count(x)) cnt++; 
	}
	cout << cnt << endl;
}
signed main(){
//	freopen("cece3.in","r",stdin);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
