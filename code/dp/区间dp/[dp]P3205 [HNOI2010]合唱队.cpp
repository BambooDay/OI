#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 19650827;
using namespace std;
int n, a[N];
int f[N][N][2];//0 right 1 left

int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		f[i][i][0] = 1;
//		if(i > 1){
//			f[i-1][i][0] = f[i-1][i][1] = 1;
//		}
//		if(i < n){
//			f[i][i+1][0] = f[i][i+1][1] = 1;
//		}
	}
	for(int len = 2; len <= n; len++){
		#define r l+len-1
		for(int l = 1; r <= n; l++){
			//f[l+1][r]
			if(a[l] < a[l+1]){
				f[l][r][0] += f[l+1][r][0];
				
			}
			if(a[l] < a[r]){
				f[l][r][0] += f[l+1][r][1];
			}
			//f[l][r-1]
			if(a[r] > a[l]){
				f[l][r][1] += f[l][r-1][0]; 
			}
			if(a[r] > a[r-1]){
				f[l][r][1] += f[l][r-1][1];
			}
			f[l][r][0] %= mod;
			f[l][r][1] %= mod;
		}
	}
	cout << (f[1][n][0] + f[1][n][1]) % mod << endl;
	return 0;
}
