#include <bits/stdc++.h>
#define int long long

using namespace std;
int a,b,r,v,m;

signed main(){
	cin >> a >> b >> r >> v >> m;
	cout << 2*a*(2*r) + b*(r) << " " << 2*a*3*v+b*v << " " << 2*a*3*m+b*m;	
	return 0;
} 
