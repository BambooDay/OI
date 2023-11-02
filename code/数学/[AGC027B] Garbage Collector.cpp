#include <bits/stdc++.h>
#define int unsigned long long
const int N = 2e5+10;
using namespace std;
int n,c;
int ans = 1e19, a[N],s[N];

signed main(){
	cin >> n >> c;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	reverse(a+1,a+1+n);
	for(int i = 1;i <= n; i++) s[i] = s[i-1]+a[i];
	for(int k = 1; k <= n; k++){
		int res = c*k+5*s[k];
		for(int i = 2; i <= (n+k-1)/k; i++) res += (2*i+1)*(s[min(n,i*k)] - s[(i-1)*k]);
		ans = min(ans,res);
	}
	cout <<ans+c*n << endl;
	return 0;
}
