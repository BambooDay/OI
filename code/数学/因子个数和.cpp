#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;

signed main(){
	int sum = 0;
	int l = 1;
	int r = 0;
	cin >> n;
	while(l <= n){
		r = n / (n/l);
		sum += (r-l+1) * (n/l);
		l = r+1;
	}	
	cout << sum;
	return 0;
}
