#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
double eps = 1e-6;
double n = 0, win = 0;
ull gcd(ull a, ull b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

ull sub(ll a, ll b) {
	if(a < b) swap(a, b);
	
	if(a >= 0 && b <= 0) {
		ull x = a, y = -b;
		return x + y;
	}
	if(a >= 0 && b > 0) return a - b;
	if(a < 0 && b <= 0) return sub(-b, -a);
}
int main(){
	ll xa,ya,xb,yb;
	while(cin >> xa >> ya >> xb >> yb) {
		n++;
		ull dx = sub(xa, xb), dy = sub(ya, yb);
//		cout << dx << " " << dy << "\n";
		if((dx == 0 && dy == 0) || gcd(dx, dy) == 1) cout << "YE5" << "\n", win++;
		else cout << "NO" << "\n";
	}
	if(win > n/2) cout << "Poor xshen!";
	else if(win < n/2) cout << "Yahoo!";
	else cout << "Friend Ship.";
	return 0;
}
