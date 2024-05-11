#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int f[N];
int a[N];
int ans = -1;
int n;
void solve(){
	ans = -1;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n,greater<int>());
	f[1] = 1;
	for(int i = 2; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j < i; j++){
			if(a[j] % a[i] == 0) f[i] = max(f[i],f[j]+1);
		}
		ans = max(ans,a[i]*f[i]);
	}
	cout << ans << "\n";
}
int main(){
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
