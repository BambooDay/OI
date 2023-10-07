#include <bits/stdc++.h>
const int N = 3e5+10;
using namespace std;
int n, f[N][65];

int main(){
	cin >> n;
	int ans = -1;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		f[i][x] = i+1;
//		ans = max(ans,x);
	}
	for(int k = 0; k <= 64; k++){
		for(int i = 1; i <= n; i++){
			if(f[i][k] == 0){
				f[i][k] = f[f[i][k-1]][k-1];
			}
			if(f[i][k]){
				ans = max(ans,k);
			}
		}
	}
	cout << ans;
	return 0;
} 
