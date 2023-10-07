#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(time(0));
int n,q;
int a[200005];
int main(){
	freopen("bbb04.in","w",stdout);
	n = 200000;
	q = 200000;
	cout << n << endl;
	for(int i  = 1; i <= n; i++){
		a[i] = 1ll*rnd()*rnd() % 1000000000 + 1 ;
	}
	for(int i = 1; i <= n/2; i++){
		a[i] = 1ll*rnd()*rnd() % 100 + 1 ;
	}
	int t = rnd() % 10;
	while(t--){
		int l = rnd()%20000;
		int r = l+rnd()%1000;
		if(l > r)
		 swap(l,r);
		for(int i = l; i <= r; i++) a[i] = a[i-1];
	}
	sort(a+1,a+1+n);
	for(int i =1;i <= n; i++) cout << a[i] << " ";
	cout << q << endl;
	for(int i =1;i <= q; i++){
		int l,r;
		l = 1ll*rnd()%200000 + 1,r = rnd() % 200000 + 1;
//		r = n;
		if(l > r) swap(l,r);
		cout << l << " " << r << endl;
	}
	return 0;
}
