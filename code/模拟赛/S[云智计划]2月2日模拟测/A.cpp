#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
double sn,k;
int n,q;
int a[N];
int ksm(int x, int b){
	if(b > 64) return 1;
	for(int i = 1;i <= b; i++) x = x / 2 + (x%2);
	return x; 
}
signed main(){
	cin >> n >> k >> q;
//	k = k*2*n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	while(q--){
		int m;
		cin >> m;
//		flag = 0;
		int ans = 0;
		for(int i =1;i <= n; i++){
			ans += ksm(a[i],m)-ksm(2*k,m)+2*k;
		}
		cout << ans << endl;
	}
	return 0;
}
