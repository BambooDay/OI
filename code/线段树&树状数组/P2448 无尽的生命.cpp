#include <bits/stdc++.h>
const int N = 1e5+10;
#define ll long long
#define int long long
using namespace std;
int n;
ll x[N],y[N];
int a[N<<1];
pair<int,int> b[N<<2];
int cnt = 0;
map<ll,int> m;
int tree[N<<2];
void modify(int x, int y){
	for(int i = x; i; i -= (i & -i)){
		tree[i] += y;
	}
}
int query(int x){
	int res = 0;
	for(int i = x; i <= cnt; i += (i & -i)){
		res += tree[i];
	}
	return res;
}
signed main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> x[i] >> y[i];
		a[i] = x[i],a[i+n] = y[i];
	}	
	sort(a+1,a+2*n+1);
	int tot = unique(a+1,a+1+2*n) - (a+1);
	for(int i = 1; i <= tot; i++){
		b[++cnt] = make_pair(cnt,1);
		m[a[i]] = cnt;
		if(i < tot && a[i+1] - a[i] > 1){
			b[++cnt] = make_pair(cnt,a[i+1] - a[i]-1);
		}
	}
	for(int i = 1; i <= n; i++){
		swap(b[m[x[i]]],b[m[y[i]]]);
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++){
		ans += query(b[i].first+1) * b[i].second;
		modify(b[i].first,b[i].second);
	}
	cout << ans;
	return 0;
}
