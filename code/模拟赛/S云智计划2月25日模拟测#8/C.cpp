#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,m;
int a[N],b[N];
int ans = 0;
signed main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	for(int i = 2;i <= n; i++) ans += abs(a[i]-a[i-1]);
	for(int i = 2;i <= m; i++) ans += abs(b[i]-b[i-1]);
	cout << ans; 
	return 0;
}
