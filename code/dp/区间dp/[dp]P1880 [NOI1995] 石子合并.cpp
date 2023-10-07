#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
const int N = 300+10;
const int M = 2e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int a[N],f[N][N],sum[N],f1[N][N];
int n;
int ma = -1, mi = INF;
signed main(){
	cin >> n;
	memset(f,0x3f,sizeof f);
	memset(f1,-0x3f,sizeof f1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int i = 1;i <= n * 2; i++){
		f[i][i] = 0;
		f1[i][i] = 0;
		sum[i] = sum[i-1] + a[i];
	}

	for(int len = 2; len <= n; len++){
		#define r l+len-1
		for(int l = 1; r <= 2*n; l++){
			for(int k = l; k < r; k++){
				f1[l][r] = max(f1[l][r],f1[l][k] + f1[k+1][r] + sum[r] - sum[l-1]);
				f[l][r] = min(f[l][r],f[l][k] + f[k+1][r] + sum[r] - sum[l-1]);
			}
		}
	}
	for(int i =1;i <= n; i++){
		ma = max(ma,f1[i][i+n-1]);
		mi = min(mi,f[i][i+n-1]);
	}
	cout << mi <<endl << ma;
	return 0;
}
