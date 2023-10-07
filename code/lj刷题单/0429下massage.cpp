#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6+10;

int n, st[N], tot[N], a[N], b[N], v[N];

int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if ( a[i] >= a[mx] ) mx = i;
	}
	for (int j = 1; j <= n - mx; j++) b[j] = a[j + mx];
	for (int j = n - mx + 1; j <= n - 1; j++) b[j] = a[j - n + mx];
	ll ans = 0;
	int idx = 0;
	for (int i = 1; i < n; i++) {
		while (idx && st[idx] < b[i]) {
			ans += tot[idx];
			idx--;
		}
		if (idx && st[idx] == b[i]) {
			ans += tot[idx];
			if (idx - 1) ans++;
			tot[idx]++;
		} else {
			if (idx) ans++;
			st[++idx] = b[i];
			tot[idx] = 1;
		}
	}
	mx = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] >= mx) {
			mx = b[i];
			if (!v[i]) ans++;
			v[i] = 1;
		}
	}
	mx = 0;
	for (int i = n - 1; i > 0; i--) {
		if (b[i] >= mx) {
			mx = b[i];
			if (!v[i]) ans++;
			v[i] = 1;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
