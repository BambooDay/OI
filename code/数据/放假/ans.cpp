#include <bits/stdc++.h>

using namespace std;
#define Mod 1000000007
int main() {
//	freopen("p15.in","r",stdin);
//	freopen("p15.out","w",stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n, l;
		scanf("%lld%lld", &n, &l);
		if (n == 1) {
			puts("0");
			continue;
		}
		n = log2(n);
		long long ans = (((l / 2) * (l - (l / 2))) % Mod) * (((1ll << (n + 1)) - 1));
		printf("%lld\n", ans % Mod);
	}
	return 0;
}
