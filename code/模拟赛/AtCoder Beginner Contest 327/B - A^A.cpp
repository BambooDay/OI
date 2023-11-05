#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n;
int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans *= a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}
signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x = ksm(i,i);
		if(x > n) break;
		if(x == n){
			cout << i << endl;
			return 0;
		}
	}	
	cout << -1 << endl;
	return 0;
} 
