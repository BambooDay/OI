#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
int n,m,k,l;
int a[N];
int w[N],x[N],v[N];
int b[N];
bool check(int t){
	for(int i = 1;i <= n; i++){
		b[i] = a[i]-a[i-1];
	}
	for(int i = 1; i <= m && w[i] <= t; i++){
		b[x[i]] -= v[i];
		b[x[i]+1] += v[i];
	}
	int now = 0;
	int tim = 0;
	for(int i = 1;i <= n; i++){
		now += b[i];
//		cout << i << " " << now << endl;
		if(now < 1){
			int delta = 1-now;
			tim += delta;
			b[i] += delta;
			b[i+k] -= delta;
			now = 1;
		}
		if(tim > t) return 0;
	}
	return 1;
}
int main(){
	cin >> n >> m >> k >> l;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	for(int i = 1; i <= l; i++){
		int r;
		cin >> r;
	}
	for(int i = 1; i<= m; i++){
		cin >> w[i] >> x[i] >> v[i];
	}
//	cout << check(1) << endl;
//	return 0;
	
	int ans = 1e6;
	int l = 0,r = 1e6;
	while(l<=r){
		int mid = (l+r)>>1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else l = mid+1;
	}
	cout << ans;
	return 0;
}
