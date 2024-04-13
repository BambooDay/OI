#include<bits/stdc++.h>
const int N = 1005;

using namespace std;
int f[N][N];
int a[N];
int n, m, sum = 0, ans = 0;
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i][1] = a[i];
		for (int j = 2; j <= n-m; j++){
			for (int k = 1; k < i; k++){
				if (a[k] <= a[i]) f[i][j] = max(f[i][j], f[k][j-1]+a[i]);
			}
		}
		for (int j = 1; j <= n-m; j++) ans = max(ans, f[i][j]);
	}
	cout << sum-ans;
	return 0;
}

