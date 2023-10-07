#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[300];
int n;
int ans = 0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++){
		int x;
		cin >> x;
		x = (x % 200 +200) % 200;
		ans += 	a[x];
		a[x]++;
	}	
	cout << ans;
	return 0;
}
