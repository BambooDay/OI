#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
double a[N];
int n;
double l = -1e9,r = 1e9;

signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++){
		if(a[i] > a[i-1]) r = min(r,(a[i]+a[i-1])/2.0);
		else l = max(l,(a[i]+a[i-1])/2.0);
	}	
	if(l > r) puts("pigeon");
	else{
		puts("lovely"); 
		cout << fixed << setprecision(7) << l+1e-6 << endl;
	}
	return 0;
}
