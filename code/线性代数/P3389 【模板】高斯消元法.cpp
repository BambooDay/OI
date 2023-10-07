#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
double a[200][200];
bool gauss() {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		while (pos <= n && fabs(a[pos][i]) == 0) {
			pos++;
		}
		if (pos > n) return 0;
		if (pos != i) {
			for (int j = 1; j <=  n + 1; j++) {
				swap(a[i][j], a[pos][j]);
			}
		}
		double t = a[i][i];
		for (int j = 1; j <= n + 1; j++) {
			a[i][j] /= t;
		}
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			t = a[j][i];
			for (int k = 1; k <= n + 1; k++) {
				a[j][k] -= a[i][k] * t;
			}

		}
	}
	return 1;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> a[i][j];
		}
	}
	if (!gauss()) puts("No Solution");
	else {
		for (int i = 1; i <= n; i++) {
			cout << setprecision(2) << fixed << a[i][n + 1] << endl;
		}
	}
	return 0;
}
