#include <bits/stdc++.h>

using namespace std;
int n;
int a[300];
int f[300][300];
int main(){
	int ans = -1;
	cin >> n;
	for(int i =1; i <= n; i++){
		cin >> a[i];
		f[i][i] = a[i];
		ans = max(ans,a[i]);
	}
	for(int len = 2; len <= n; len++){
		for(int l = 1; l <= n; l++){
			#define r l + len-1
			if(r > n)break;
			for(int k = l; k <= r; k++){
				if(f[l][k] == f[k+1][r] && f[l][k]){
					f[l][r] = max(f[l][r],f[l][k]+1);
					ans = max(ans,f[l][r]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
