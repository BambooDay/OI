#include <bits/stdc++.h>

using namespace std;
int n, t;
int a[201][201];
void mul(int x[201][201],int y[201][201],int z[201][201]){
	int c[201][201]; 
	for(int i = 1; i <= n*10; i++){
		for(int j = 1;j <= 10*n; j++){
			c[i][j] = 0;
			for(int k = 1; k <= 10*n;k++){
				c[i][j] = (c[i][j] + x[i][k]*y[k][j] % 2009)%2009;
			}
		}
	}
	for(int i = 1;i <= n*10;i ++){
		for(int j = 1;j <= n*10; j++){
			z[i][j] = c[i][j];
		}
	}
}
int ksm(int b){
	int ans[201][201] = {0};
	for(int i = 0; i <= n*10; i++) ans[i][i] = 1;
	while(b){
		if(b & 1){
			mul(a,ans,ans);
		}
		mul(a,a,a);
		b >>= 1;
	}
	return ans[1][n];
}
int main(){
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 8; j++){
			a[i+j*n][i+(j-1)*n] = 1;
		}
		for(int j = 1;j <= n; j++){
			char ch;
			cin >> ch;
			if(ch-'0')
				a[i][j+(ch-'0'-1)*n] = 1;
		}
	}		
//	for(int i = 1;i <= n*10; i++){
//		for(int j = 1;j <= n*10; j++){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << ksm(t);
	return 0;
}
