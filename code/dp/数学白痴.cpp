#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int len, a[N];
string s;
long long dp[N];
int main() {
	cin >> s;
	len = s.size();
	for (int i = 1; i <= len; i++)
		a[i] = s[i - 1] - '0';
	dp[0] = 1;
	for (int i = 1; i <= len; i++) {
		dp[i] = dp[i - 1] * (a[i] + 1);
		if (i >= 2 && a[i - 1] == 1)
			dp[i] += dp[i - 2] * (9 - a[i]);
	}
	printf("%lld", dp[len]);
	return 0;
}
