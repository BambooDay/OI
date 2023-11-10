#include <bits/stdc++.h>
#define ull unsigned long long 
#define int unsigned long long
const ull BASE = 13331;
const int N = 1e5+10;

using namespace std;
int n,m;
string s,t;
ull base[N];
ull hs[N],ht[N];
void init(){
	cin >> s >> t;
	n = s.size(),m = t.size();
	hs[0] = 0;
	for(int i = 1; i <= n ;i++) hs[i] = hs[i-1]*BASE + s[i-1];
	ht[0] = 0;
	for(int i = 1; i <= m; i++) ht[i] = ht[i-1]*BASE + t[i-1]; 
}
ull val(ull h[], int l, int r){
	return (h[r]-h[l-1]*base[r-l+1]);
}
int get(int x, int y, int len){
	int l = 1,r = len;
	int ans = 0;
	while(l <= r){
		int mid = (l+r) >> 1;
//		cout << mid << " " << val(hs,x,x+mid-1) << " " <<  val(ht,y,y+mid-1) << endl; 
		if(val(hs,x,x+mid-1) == val(ht,y,y+mid-1)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	return ans+1;
}
bool check(int x){
	int y = 1,r = x+m-1;
	for(int i = 1;i <= 3; i++){
		int tmp = get(x,y,m-y+1);
//		cout << tmp << endl;
		x += tmp;
		y += tmp;
		if(y > m) return 1;
	}
	return val(hs,x,r) == val(ht,y,m);
}
void solve(){
	init();
	int ans = 0;
//	cout << hs[1] << " " << hs[0] << " "<< hs[1]-hs[0]*base[1] << endl;
//	cout << val(hs,1,1);
//	cout << check(1) << endl;
//	return;
	for(int i =1; i <= n-m+1; i++) if(check(i)){
//		cout << i << endl; 
		ans++;
	} 
	
	cout << ans << endl;
}
signed main(){
	base[0] = 1;
	for(int i = 1; i <= N-10; i++) base[i] = base[i-1]*BASE;
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
/*
1
132132113213212313132123322123321311
12312
31313
*/
