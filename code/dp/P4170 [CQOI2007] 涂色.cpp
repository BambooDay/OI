#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int f[60][60];
int main(){
	cin >> s;
	n = s.size();
	s = " " + s;
	memset(f,0x3f,sizeof f);
	for(int i = 1;i <= n; i++){
		f[i][i] = 1;
	}	
	for(int len = 2; len <= n; len++){
		for(int l = 1; l <= n; l++){
			#define r l+len-1
			if(r > n) break;
			if(s[l] == s[r]){
				f[l][r] = f[l][r-1];
			}
			for(int k = l; k < r; k++){
				f[l][r] = min(f[l][r],f[l][k] + f[k+1][r]);
			}
		}
	}
	cout << f[1][n];
	return 0;
}
