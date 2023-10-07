#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
void multipy(ll a[3][3], ll b[3][3], ll c[3][3], int x, int y, int z){//c=a*b 
	ll d[3][3];
	for(int i = 0; i < x; i++){
		for(int j = 0; j < z; j++){
			d[i][j] = 0;
			for(int k = 0; k < y; k++){
				d[i][j] = (d[i][j] + a[i][k]*b[k][j]) % mod;
			}
		}
	}
	for(int i = 0;i < x; i++){
		for(int j = 0; j < z; j++){
			c[i][j] = d[i][j];
		}
	}
}
void mksm(ll a[3][3], ll b){
	ll x[3][3] ={{1,0,0},{0,1,0},{0,0,1}};
	while(b){
		if(b & 1){
			multipy(a,x,x,3,3,3);
		}
		multipy(a,a,a,3,3,3);
		b >>= 1; 
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0;j < 3; j++){
			a[i][j] = x[i][j];
		}
	}
}

void solve(){
	ll n;
	ll K[3][3] = {{1,0,1},{1,0,0},{0,1,0}};
	ll A[3][3] = {{1},{1},{1}};
	cin >> n;
 	if(n <= 3){
 		cout << 1 << endl;
 		return;
 	}
 	mksm(K,n-3);
 	multipy(K,A,A,3,3,1);
 	cout << A[0][0] << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
