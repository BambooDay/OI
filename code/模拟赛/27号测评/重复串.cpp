#include <bits/stdc++.h>
#define int unsigned long long
const int N = 2e6+10;
const int BASE = 10;
using namespace std;
int base[N];
int hs[N];
string s;
int n;
bool check(int m){
//	cout<<hs[m] << " " << hs[n] << " " << base[n] << " " << hs[m+n] << endl; 
	int x = hs[n],y = hs[m+n]- hs[m]*base[n];
	if(x == y) return 1;
	return 0; 
}
void solve(){
	n = s.size();
	string t =  " " + s + s;
	s = " " + s;
	hs[0] = 0;
	for(int i = 1;i <= n*2; i++){
		hs[i] = hs[i-1]*BASE+t[i]-'a'+1;
	}
//	cout << check(2);
//	return;
	for(int i = 1; i <= n; i++){
		if(check(i)){
			cout << n/i << endl; 
			return;
		}
	}
}
signed main(){
	base[0] = 1;
	for(int i = 1; i <= 2e6+1; i++){
		base[i] = base[i-1]*BASE;
	}
	while(cin >> s && s != "."){
		solve();
	}
	return 0;
}
