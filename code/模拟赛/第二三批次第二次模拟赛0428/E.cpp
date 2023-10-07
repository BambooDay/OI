#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, k;
ll a[N];
bool check(ll len){
	ll tot = 0;
	for(int i = 1;i <= n;i++){
		tot += a[i] / len;
		if(tot >= k) return 1;
	}
	return 0;
}
int main(){
	cin >> n >> k;
	ll l = 1, r = -1;
	for(int i = 1; i <= n; i++){
		double x;
		cin >> x;
		a[i] = x*100;
		r = max(a[i],r);
	}
	double ans;
	while(l < r){
		ll mid = (l+r) >> 1;
		if(check(mid)){
			ans =  mid;
			l = mid+1;
		}else{
			r = mid;
		}
	}
	ans /= 100.0;
	cout << setprecision(2) << fixed << ans;
	return 0;
}
