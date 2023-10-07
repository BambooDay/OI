#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const ll INF = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
ll w;
bool check(ll mid){
	return (3*pow(2,(mid-3))) >= w;
}
void solve(){
	cin >> w;
	ll l = 1,r = w;
	ll ans = INF;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			r = mid-1;
			ans = min(ans,mid);
		}else l = mid+1;
	}
	cout << ans << endl;	
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
