#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;

using namespace std;
void mul(int A[105][105],int B[105][105], int C[105][105],int x, int y, int z){
	int d[105][105];
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= z; j++){
			d[i][j] = 0;
			for(int k = 1; k <= y; k++){
				d[i][j] = (d[i][j] + A[i][k] * B[k][j]%mod)%mod;
			}
		}
	}
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= z; j++){
			C[i][j] = d[i][j];
		}
	}
}
int base[105][105];
int mans[105][105];
int n,k;
int res[105][105];
//int v[100005];
int K;
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> n >> k;
	K = k;
	for(int i = 1;i <= n; i++){
		int v;
		cin >> v;
		base[1][v]++;
		base[101][v]++;
	}	
	for(int i = 2; i <= 100;i++){
		base[i][i-1] = 1;
		mans[i][i] = 1;
	}
	base[101][101] = 1;
	mans[1][1] = 1;
	mans[101][101] = 1;
	res[1][1] = 1;
	res[101][1] = 1;
	
//	for(int i = 1;i <= 101; i++){
//		for(int j = 1;j <= 101; j++){
//			cout << mans[i][j] << " ";
//		}
//		cout << endl;
//	}
	
//	k += 2;
	while(k){
		if(k&1){
			mul(mans,base,mans,101,101,101);
		}
		mul(base,base,base,101,101,101);
		k >>= 1;
	}
	mul(mans,res,res,101,101,1);
	cout << res[101][1];
	return 0;
}
