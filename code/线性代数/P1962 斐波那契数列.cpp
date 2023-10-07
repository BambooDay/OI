#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9+7;

using namespace std;
ll n;
void multipy(ll a[2][2], ll b[2][2], ll c[2][2], int x, int y, int z){//c=a*b 
	ll d[2][2];
	for(int i = 0; i < x; i++){
		for(int j = 0; j < z; j++){
			d[i][j] = 0;
			for(int k = 0; k < y; k++){
				d[i][j] = (d[i][j] + a[i][k]*b[k][j] % mod) % mod;
			}
		}
	}
	for(int i = 0;i < x; i++){
		for(int j = 0; j < z; j++){
			c[i][j] = d[i][j];
		}
	}
}
void mksm(ll a[2][2], ll b){
	ll x[2][2] ={{1,0},{0,1}};
	while(b){
		if(b & 1){
			multipy(a,x,x,2,2,2);
		}
		multipy(a,a,a,2,2,2);
		b >>= 1; 
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0;j < 2; j++){
			a[i][j] = x[i][j];
		}
	}
}
ll K[2][2] = {{1,1},{1,0}};
ll A[2][2] = {{1},{1}};

int main(){
	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}
	if(n <= 2){
		cout << 1;
		return 0;
	}
	mksm(K,n-2);
	multipy(K,A,A,2,2,1);
	cout << A[0][0] % mod;
	return 0;
}
