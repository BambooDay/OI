#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
ll k;
ll a[200][200];
void mult(ll a[200][200],ll b[200][200],ll c[200][200],int x, int y, int z){
	ll d[200][200];
	for(int i = 0;i < x; i++){
		for(int j = 0; j < z; j++){
			d[i][j] = 0;
			for(int k = 0; k < y; k++){
				d[i][j] = (d[i][j]+a[i][k] * b[k][j]) % mod;
			}
		}
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < z; j ++){
			c[i][j] = d[i][j];
		}
	}
}
void init(ll a[200][200],int x){
	for(int i = 0; i < x; i++) a[i][i] = 1;
}

void mksm(ll a[200][200],ll b, int x){
	ll ans[200][200];
	init(ans,x);
	while(b){
		if(b&1){
			mult(ans,a,ans,x,x,x);
		}
		b >>= 1;
		mult(a,a,a,x,x,x);
	}
	for(int i = 0;i < x; i++){
		for(int j = 0;j < x;j++){
			a[i][j] = ans[i][j];
		}
	}
}
int main(){
//	freopen("P3390_1.in","r",stdin);
	cin >> n >> k;
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> a[i][j];
		}
	}
	mksm(a,k,n);
	for(int i = 0;i < n; i++){
		for(int j = 0;j < n; j++){
			cout << a[i][j] << " "; 
		}
		cout << endl;
	}
	return 0;
}

