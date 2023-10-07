#include <bits/stdc++.h>
using namespace std;
int a[100011];
int n, sum;
void solve() {
	cin >> n;
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n) {
		puts("-1");
		return;
	}
	sum /= n;
	cout << 3 * (n - 1) << endl;
	for (int i = 2; i <= n; i++) {
		int x = a[i] % i;
		cout << 1 << " " << i << " " << (i - x) % i << endl;
		a[1] -= (i - x) % i;
		a[i] += (i - x) % i;
		cout << i << " " << 1 << " " << a[i] / i << endl;
		a[1] += a[i];
		a[i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		cout << 1 << " " << i << " " << sum << endl;
		a[1] -= sum;
		a[i] += sum;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
