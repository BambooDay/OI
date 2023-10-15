#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans = 0;
signed main(){
	freopen("A10.in","r",stdin);
	freopen("A10.out","w",stdout);
	cin >> n;
	while(n){
		ans += n % 60;
		n /= 60;
	}
	cout << ans << endl;
	return 0;
}
