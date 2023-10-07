#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
using namespace std;
int n, p0, p1;
int p[2005];
char s[2005];
ll g[2003],ans;
ll f[21003][2003];

int main(){
	scanf("%d %s",&n,s+1);
	for(p0 = 0; p0 <= n && s[n-p0] == '0';++p0);
	for(p1 = 0; p1 <= n && s[n-p1] == '1';++p1);
	for(int l = 1;l <= n; l++){
		for(p[l]=0; p[l] <= l && s[l-p[l]] == s[n-p[l]];p[l]++);
	}
	for(int k = 1; k <= n; k++){
		for(int l = 1; l+k-1 <= n; l++){
			if(p[l+k-1]<k){
				f[k][l] = (f[k-p[l+k-1]-1][l]+1+f[k-p[l+k-1]-1][n-k+1])%mod;
			}
		}
		if(p0<k){
			g[k] = (g[k-p0-1]+1+f[k-p0-1][n-k+1])%mod;
		}
	}
	for(int k = n - p1 -1; k >= 0; k-=(p1+1)){
		ans = (ans+f[k][n-p1-k]+1)%mod;
	}
//	cout << ans % mod;
	cout << (ans+g[n]+1)%mod; 
	return 0;
}
