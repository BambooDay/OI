#include <bits/stdc++.h>
#define int long long

using namespace std;
int f[(1<<16)+10][65];
int n;
int b;

signed main(){
	cin >> n >> b;
	for(int i = 0; i < (1<<16); i++){
		int ne = i;
		if((i>>(n-1))&1) ne ^= 1;
		for(int j = 1; j < n; j++){
			if((i>>(j-1))&1) ne ^= (1<<(j));
		}
		f[i][0] = ne; 
	}	
	for(int j = 1; j <= 50; j++){
		for(int i = 0; i < (1<<16); i++){
			f[i][j] = f[f[i][j-1]][j-1];	
		}
	}	
	int nw = 0;
	for(int i = 1;i <= n; i++){
		int x;
		cin >> x;
		nw = (nw<<1)+x;		
	}
	for(int i = 50; i >= 0; i--){
		if(b >> i){
			nw = f[nw][i];
			b >>= i;
		}
	}
	cout << nw;
	return 0;
}
