#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1250 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;
int n;
double f[N][N];
int main() {
	scanf("%d", &n);
	n /= 2;
	if (n == 1 || n == 0) {
		printf("0.0000");
		return 0;
	}
	f[1][0] = f[0][1] = 0.5;
	for (int i = 2; i <= n; i++) f[i][0] = f[0][i] = 0.5 * f[0][i - 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n) {
				f[i][j] += f[i][j - 1];
			} else {
				f[i][j] += f[i][j - 1] / 2;
			}
			if (j == n) {
				f[i][j] += f[i - 1][j];
			} else{
				f[i][j] += f[i - 1][j] / 2;
			} 
		}
	}
	printf("%.4lf", f[n][n - 2] + f[n - 2][n]);
	return 0;
}
