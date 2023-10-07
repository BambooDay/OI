#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;

signed main(){
	cin >> n >> k;
	int ans = k*n;
	//k-i*[k/i]
	int l = 1, r = 0;
	int sum = 0;
	while(l <= min(k,n)){
		r =min( k/(k/l),n);
		sum += (r-l+1)*(k/l)*(l+r)/2;
		l = r+1;
	}	
//	cout << ans << " " <<sum << endl;
	ans -= sum;
	cout << ans; 
	return 0;
}
