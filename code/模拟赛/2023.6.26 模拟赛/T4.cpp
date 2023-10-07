#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;
int n;
string s;
int B[N], C[N], S[N];
int main() {
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		B[i] = B[i - 1] + (s[i] == 'B');
		C[i] = C[i - 1] + (s[i] == 'C');
		S[i] = S[i - 1] + (s[i] == 'S');
	}
	int ans = 1;
	for (int i = 1; i <= 3; ++i)
		for (int j = i + 1; j <= n; ++j) {
			int cb = B[j] - B[i - 1];
			int cc = C[j] - C[i - 1];
			int cs = S[j] - S[i - 1];
			if (cb != cc && cc != cs && cs != cb)
				ans = max(ans, j - i + 1);
		}
	for (int j = n - 2; j <= n; ++j)
		for (int i = 1; i <= j - 1; ++i) {
			int cb = B[j] - B[i - 1];
			int cc = C[j] - C[i - 1];
			int cs = S[j] - S[i - 1];
			if ((cb != cc && cc != cs && cs != cb)||(!cb&&!cc)||(!cc&&!cs)||(!cb&&!cs))
				ans = max(ans, j - i + 1);
		}
	cout << ans << endl;
	return 0;
}
