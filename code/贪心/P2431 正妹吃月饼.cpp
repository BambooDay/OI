#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int ans = 0;
int a,b;

signed main(){
	cin >> a >> b;
	while((a|(a+1)) <= b) a = (a | (a+1));
	while(a) ans += (a&1), a >>= 1;
	cout << ans << endl;	
	return 0;
}
