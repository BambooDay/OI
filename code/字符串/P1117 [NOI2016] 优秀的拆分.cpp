#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 30005;

int a[maxn], b[maxn];
long long w[maxn], p[maxn];
char s[maxn];

inline int get(int l, int r) {
	return ((w[r] - w[l - 1] * p[r - l + 1]) % mod + mod) % mod;
}

int n, now;

int lcp(int x, int y) {
	int l = 0, r = now;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (get(x - mid + 1, x) == get(y - mid + 1, y))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int lcs(int x, int y) {
	int l = 0, r = n - y + 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (get(x, x + mid - 1) == get(y, y + mid - 1))
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%s", s + 1);
		n = strlen(s + 1);
		p[0] = 1;
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] * 31 % mod;
			w[i] = (w[i - 1] * 31 + s[i] - 'a') % mod;
		}
		for (int len = 1; len <= n; len++) {
			int j = len, k = len << 1;
			now = len;
			while (k <= n) {
				int LCP = lcp(j, k), LCS = lcs(j, k);
				int hd = max(k - LCP + len, k), tl = min(k + LCS - 1, k + len - 1);
				if (hd <= tl) {
					a[hd]++, a[tl + 1]--;
					b[hd - len * 2 + 1]++, b[tl - len * 2 + 2]--;
				}

				j += len, k += len;
			}
		}

		for (int i = 1; i <= n; i++)
			a[i] += a[i - 1], b[i] += b[i - 1];
		long long answer = 0;
		for (int i = 1; i < n; i++)
			answer += a[i] * b[i + 1];
		printf("%lld\n", answer);
	}
	return 0;
}
