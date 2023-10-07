#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int c,a[N],p[N],now,ans;

bool check(int x){
	int t = 0,k = -1;
	while(t < c){
		if(a[p[c]] - a[p[t]] < x) break;
		int l = t + 1, r = c;
		while(l < r){
			int mid = (l + r) >> 1;
			if(a[p[mid]] - a[p[t]] < x) l = mid + 1;
			else r = mid;
		}
		k++,t = l;
	}
	if( k < 1) return 1;
	if(ans < k * (x + 1) + x){
		ans = k * (x + 1) + x,now = x;
	}
	return 0;
}
void solve(){
	string s;
	ans = now = -1, c = 0;
	cin >> s;
	s = ' ' + s;
	int n = s.size();
	s = s + '1';
	for(int i = 1; i <= n; i++){
		if(s[i] == '0') a[i] = a[i-1] + 1;
		else a[i] = a[i-1],p[++c] = i;
	}
	for(int i = 1; i <= n; i++){
		if(check(i)) break;
	}
	cout << ans << " " << now << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
