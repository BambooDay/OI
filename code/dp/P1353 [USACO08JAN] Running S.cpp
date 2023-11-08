#include <bits/stdc++.h>
const int N = 1e4+10;

using namespace std;
int n,m;
int d[N];
int f[N][505];
 
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> d[i];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= min(i,m); j++){
			f[i][0] = max(f[i][0],f[i-j][j]);
		}
		f[i][0] = max(f[i][0] ,f[i-1][0]);
		for(int j = m; j >= 1; j--){
			f[i][j] = max(f[i][j],f[i-1][j-1]+d[i]);
		}
	}	
	cout << f[n][0];
	return 0;
}
