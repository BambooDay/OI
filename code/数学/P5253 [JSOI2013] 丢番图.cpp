#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const ll INF = 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

long long n;
int main(){
	std::cin >> n;
	long long ans = 1;
	for (long long i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			long long k = 0;
			while (1) {
				if (n % i != 0) break;
				n /= i;
				++k;
			}
			ans *= (k << 1) + 1;
		}
	if (n > 1){
		ans *= 3;
	}
	printf("%lld", (ans + 1) >> 1);
	return 0;
}
