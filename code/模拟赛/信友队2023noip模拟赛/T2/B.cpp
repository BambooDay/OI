#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,m,a[N],p;
int c[N],b[N];
int tr[N];
void modify(int x){
	for(int i = x; i; i -= (i&-i)){
		tr[i]++;	
	}
} 
int query(int x){
	int ans = 0;
	for(int i = x; i <= n; i += (i&-i)){
		ans += tr[i];
	} 
	return ans;
}
int ans = 0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}	
	while(m--){
		ans = 0;
		memset(tr,0,sizeof tr);
		cin >> p;
		for(int i = 1; i <= n; i++){
			b[i] = a[i]^p;
			c[i] = b[i];
		}
		sort(c+1,c+1+n);
		for(int i = 1;i <= n; i++){
			int now = lower_bound(c+1,c+1+n,b[i]) - c;
			ans +=  query(now);
			modify(now);
		}
		cout << ans <<endl;
	} 
	return 0;
}
