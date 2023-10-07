#include <bits/stdc++.h>
const int N = 2e4+10;
const int BASE = 13331;
#define int unsigned long long
using namespace std;
int hs[N],base[N];
int n,k;
int a[N];
int get(int l, int r){
//	cout << hs[r] << " " << hs[l-1]*base[r-l] << endl;
	return hs[r] - hs[l-1] * base[r-l+1];
}
bool check(int len){
	map<long long, int> m;
//	bool flag = 1;
	for(int i = 1; i+len-1 <= n; i++){
		int now = get(i,i+len-1);
		m[now]++;
		if(m[now] >= k) return 1;
	}
	return 0;
}
int ans = 0;
signed main(){
//	freopen("P2852_2.in","r",stdin);
	cin >> n >> k;
	base[0] = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		hs[i] = hs[i-1] * BASE + a[i];
		base[i] = base[i-1] * BASE;
	}
//	cout <<endl <<  get(2,3);
//	check(2);
//	return 0;
	int l = 1,r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
