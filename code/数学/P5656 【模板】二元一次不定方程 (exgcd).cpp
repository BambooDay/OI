#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c;
int exgcd(int a, int b, int &x, int &y){
	if(!b){
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b,a%b,y,x);
	y -= a/b*x;
	return d;
}
void solve(){
	cin >> a >> b >> c;
	int x,y;
	int g = exgcd(a,b,x,y);
	if(c%g){
		cout << -1 << endl;
		return;
	}
	x *= c/g,y *= c/g;
	int dx = b/g,dy = a/g;
	int l = ceil((-x*1.0+1.0)/(1.0*dx)),r = floor((double)(y-1)/dy);
	if(l > r){
		cout << x+l*dx << " " << y-r*dy << endl;
		return;
	}
	cout << r-l+1 << " ";
	cout << x+l*dx << " " << y-r*dy << " ";
	cout << x+r*dx << " " << y-l*dy << endl;
	return;
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
