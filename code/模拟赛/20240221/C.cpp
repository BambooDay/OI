#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;

using namespace std;
int n,k,m,c,d;
int a[N];
int b[N];
void update(int l , int r){
	if (l > r) return ;
	b[l]++,b[r + 1]--;
}
bool check(int x){
	for(int i = 1; i <= n - m + 1; i++) b[i] = 0;
	for(int i = 1; i <= n ; i++){
		if(a[i] >= x){
			b[1] ++;
		}else{
			int tmp ;
			if (d){
				tmp = (x - a[i] - c + d - 1) / d;
				if (tmp < 0) tmp = 0;
				if (tmp >= m) continue;
			}else{
				if(a[i] + c >= x) tmp = 0;
				else continue;
			}
			int r = i - tmp, l = i - m + 1;
			update(max(1ll, l), min((n - m + 1), r));
		}
	}
	int maxn = 0, num = 0;
	for(int i = 1; i <= n; i++){
		num += b[i];
		maxn = max(maxn, num);
	}
	return maxn >= k;
}
signed main(){
	freopen("music.in","r",stdin);
	freopen("music.out","w",stdout);
	cin >> n >> k >> m >> c >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = 0, r = 1e18;
	int ans;
	while(l <= r){
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid,l = mid+1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

