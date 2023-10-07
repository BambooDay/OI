#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;

ll m, a, c, x0,n,g;
//ll mod;
#define mod m
ll ksx(ll x, ll y){
	ll z = 0;
	while(y){
		if(y & 1){
			z = (z + x) % mod; 
		}
		y >>= 1;
		x = (x+x)% mod;
	}
	return z;
}
void multipy(ll a[2][2], ll b[2][2], ll c[2][2], int x, int y, int z){//c=a*b 
	ll d[2][2];
	for(int i = 0; i < x; i++){
		for(int j = 0; j < z; j++){
			d[i][j] = 0;
			for(int k = 0; k < y; k++){
				d[i][j] = (d[i][j] + ksx(a[i][k],b[k][j])) % mod;
			}
		}
	}
	for(int i = 0;i < x; i++){
		for(int j = 0; j < y; j++){
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
ll K[2][2] = {{1,1},{0,1}};
ll A[2][2] = {{1},{1}};
int main(){
	cin >> m >> a >> c >> x0 >> n >> g;
//	mod = g;
	K[0][0] = a,A[0][0] = x0,A[1][0] = c;

	mksm(K,n);

	multipy(K,A,A,2,2,1);
	cout << A[0][0]%g;
	return 0;
}
