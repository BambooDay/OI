#include <bits/stdc++.h>
const int N = 1005;
using namespace std;;
int n;
int a[N];
int l[N][N],r[N][N];
int s[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		l[i][i] = r[i][i] = a[i];
		s[i] = s[i-1] + a[i]; 
	}
	for(int len = 1; len <= n; len++){
		for(int i = 1; i <= n; i++){
			#define j (i+len)
			if(j > n) break;
			l[i][j] = a[i] + max(l[i+1][j],s[j] - s[i] - max(l[i+1][j], r[i+1][j]));
			r[i][j] = a[j] + max(r[i][j-1],s[j-1]-s[i-1]-max(l[i][j-1],r[i][j-1]));
		}
	}
	cout << max(l[1][n],r[1][n]) << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
} 
