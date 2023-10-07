#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int jc,jj,dn; 
int main(){
	for(int i =1;i <= 8; i++){
		int x;
		cin >> x;
		jc += x ;
	}
	for(int i = 1;i <= 4; i++){
		int x;
		cin >>x;
		jj += x;
	}
	for(int i =1;i <= 3; i++){
		int x;
		cin >> x;
		dn += x; 
	}
	int ans = jc;
	if(jc >= 80){
		ans += jj;
		if(jj >= 40) ans += dn;
	} 
	cout << ans << endl;
	return 0;
}
