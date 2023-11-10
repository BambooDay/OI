#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,m;
int ans = 0;
signed main(){
	cin >> a >> b >> c >> d >> m;
	ans += c*5;
	if(ans > m) ans += d*20; 
	ans -= (b-d)*20;
	cout << max(ans,0ll);
	return 0;
}
