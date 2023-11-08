#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;
 
using namespace std;
int n,m,a[N],sum,ans,l,r,sum2,num;
double now;
bool check() {
	return sum2*1.0 - 2*now*sum + now*now*num <= m;
}
signed main() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	now = a[1];
	sum = a[1];
	sum2 = a[1]*a[1];
	l = 1;
	r = 1;
	num = ans = 1;
	while(1){
		if(check()) {
			ans = max(ans,num);
			r++;
			if(r > n) break;
			sum += a[r];
			sum2 += a[r]*a[r];
			num++;
			now = (double)sum/num;
		} else {
			sum -= a[l],sum2-=a[l]*a[l];
			num--;
			now = (double)sum/num;
			l++;
		}
	}
	cout << n-ans;
	return 0;
}

