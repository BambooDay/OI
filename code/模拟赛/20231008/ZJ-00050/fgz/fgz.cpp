#include <bits/stdc++.h>
#define int long long

using namespace std;
int n,m;
int gcd(int x, int y){
	if(!y) return x;
	return gcd(y,x%y);
}
void solve(){
	cin >> n >> m;
	n *= 2;
	m *= 2;
	cout << n*m / gcd(n,m) << endl;	
}
signed main(){
	freopen("fgz.in","r",stdin);
	freopen("fgz.out","w",stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
} 
