#include <bits/stdc++.h>
const double eps = 1e-3;
const int N = 1e5+10;
#define int long long
using namespace std;
int a[N],c[N];
double p[N],q[N];
int n,k;
bool check(double t){
	int cnt = 0;
	for(int i = 1;i <= n; i++){
		double x = a[i]*1.0*c[i],y = t*a[i];
		p[i] = x-y;
		q[i] = y-x;
		if(q[i]-p[i] < eps) cnt--;
	}
	sort(p+1,p+1+n);
	sort(q+1,q+1+n);
	int l = 0,r = 1;
	while(r<=n){
		while(q[l+1]-p[r] < eps && l+1<=n) l++;
		cnt += l;
		r++; 
	}
	return cnt/2 < k;
}
double ans;
signed main(){
	cin >> n >> k;
	for(int i = 1;i <= n; i++) cin >> a[i] >> c[i];
	double l = 1,r = 1e10;
	while(r-l >= eps){
		double mid = (l+r)/2;
		if(check(mid)){
			r = mid;
			ans = mid;
		}else l = mid;
	}
	cout << fixed << setprecision(3) << ans << endl;
	return 0;
}
