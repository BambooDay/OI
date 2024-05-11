#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 2e5 + 5, INF = (1 << 30);

int T, n;
int a[N], b[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) std::cin >> a[i];
	for (int i = 1; i <= n; i++) std::cin >> b[i];

	int minR = INF, maxL = -INF;
	for (int i = 1; i <= n; i++) {
		minR = min(minR, std::max(a[i], b[i]));
		maxL = max(maxL, std::min(a[i], b[i]));
	}

	i64 sum = (minR <= maxL ? 2 * (maxL - minR) : 0);
	for (int i = 1; i <= n; i++) sum += abs(a[i] - b[i]);

	cout << sum << "\n";
}

int main() {

	cin >> T;
	while (T--) solve();

	return 0;
}
