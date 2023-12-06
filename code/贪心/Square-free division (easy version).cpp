#include <bits/stdc++.h>
const int N = 2e5+10;
//#define int long long

using namespace std;
int read(){
	int x,y;
	cin >> x;
	y = x;
	for(int i = 2;i*i<= x; i++){
		int cnt = 0,tmp = 1;
		while(x%i == 0) cnt++,x /= i,tmp *= i;
		if(cnt%2==0) y /= tmp;
		else y /= tmp/i;
	}
	return y;
}
int n,k,a[N],ans;
map<int,bool> m;
void solve(){
	cin >> n >> k;
	for(int i =1;i <= n; i++){
		cin >> a[i];
		for(int j = 2; j*j<= a[i]; j++){
			int cnt = 0;
			while(a[i] % j == 0) a[i] /= j, cnt++;
			if(cnt&1) a[i] *= j;
		}
	} 
	ans = 1;
	m.clear();
	for(int i = 1; i <= n; i++){
		if(m.count(a[i])){
			ans++;
			m.clear();
		}
		m[a[i]] = 1;
	}
	cout << ans << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
