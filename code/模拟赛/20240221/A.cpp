#include <bits/stdc++.h>
#define int long long
const int N = 3e5+10;

using namespace std;
int n,m;
int a[N];
bool check(int x){
	int cnt = 0;
	for(int i = 1;i <= m; i++){
		cnt += a[i] / x + !!(a[i]%x);
	}
	return cnt <= n;
}
signed main(){
	freopen("bear.in","r",stdin);
	freopen("bear.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m; i++) cin >> a[i];
	int l = 1,r = 1e9;
	int ans = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)) ans = mid,r = mid-1;
		else l = mid+1; 
	}	
	cout << ans;
	return 0;
}
