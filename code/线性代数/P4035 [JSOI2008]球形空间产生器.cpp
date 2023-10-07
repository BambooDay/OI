#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
double a[20][20];
double b[20][20];
void gauss() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		while (pos <= n && b[pos][i] == 0) {
			pos++;
		}
		if (pos != i) {
			for (int j = 1; j <= n + 1; j++) {
				swap(b[pos][j], b[i][j]);
			}
		}
		double t = b[i][i];
		for (int j = 1; j <= n + 1; j++) {
			b[i][j] /= t;
		}
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			t = b[j][i];
			for (int k = 1; k <= n + 1; k++) {
				b[j][k] -= t * b[i][k];
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (i) {
				b[i][j] = (a[i - 1][j] - a[i][j])*2;
				b[i][n + 1] += a[i - 1][j] * a[i - 1][j] - a[i][j] * a[i][j];
//				b[i][n + 1] /= 2;
			}
		}
	}
	gauss();
	for(int i = 1;i <= n; i++){
		cout << setprecision(3) << fixed << b[i][n+1] << " ";
	}
	return 0;
}
