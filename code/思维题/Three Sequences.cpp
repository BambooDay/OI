#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
int n, sum, a[N],b[N];
int q;
int hf(int x){
	if(x > 0) return x / 2;
	if(x % 2) return x / 2 -1;
	return x / 2; 
}
signed main(){
	cin >> n;
	for(int i =1;i <= n; i++) cin >> a[i];
	for(int i =1;i <= n; i++) b[i] = a[i] - a[i-1];
	sum = b[1];
	for(int i = 2;i <= n; i++) sum += max(0ll,b[i]);
	cout << hf(sum+1) << endl;
	cin >> q;
	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		if(l != 1) sum -= max(b[l],0ll),b[l] += k, sum += max(0ll,b[l]);
		else sum -= b[l],b[l] += k, sum += b[l];
		if(r != n) sum -= max(b[r+1], 0ll), b[r+1] -= k,sum += max(0ll,b[r+1]);
		cout << hf(sum +1) << endl;
	}
	return 0;
}
