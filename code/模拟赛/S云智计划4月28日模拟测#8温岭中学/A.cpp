#include <bits/stdc++.h>
#define int long long
const int N = 4e6+10;

using namespace std;
int n,q,d;
int a[N];
int op[N];
int st = N;

signed main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin >> n >> d >> q;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		op[i] = -1e18;
	}	
	for(int i = 1; i <= q; i++){
		int l,x;
		scanf("%lld%lld",&l,&x);
		op[l] = max(op[l],x);
		st = min(st,l);
//		if(l == 999998) cout <</ -1 << endl;
//		if(l < n) return -1;
	}
//	return (st==n);
	int x = op[st];
//	if(x == 1e-18) return -1;
//	cout << op[999998] << endl;
	for(int i = st; i <= n; i++){
		if(op[i] > ((i-st)*d+x)) st = i,x = op[i];
//		if(i == n-2){
//			
//			cout  << a[i] << " " << x <<" " << st << " " << d << endl; 
//		}
		a[i] = max(a[i],x+(i-st)*d);
	}
	for(int i = 1;i <= n; i++){
		printf("%lld ",a[i]);
	}
	return q;
}
