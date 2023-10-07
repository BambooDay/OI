#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count()); 

i64 rnd(i64 l, i64 r) {
	return mt_rand() % (r - l + 1) + l;
}

int main() {
	freopen("seg15.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	int t = 18, n = (1 << t), m = 100000;
	cout << n << " " << m << "\n";
	rep(i, 1, n) cout << rnd(1, 1000000000) << " ";
	cout << "\n";

	while(m--) {
		int op = rnd(1,4) % 2 ? 3 : 4;

		if(op == 1) {
			int x = rnd(1, n), y = rnd(1, 5);
			cout << op << " " << x << " " << y << "\n";
		}

		if(op == 2) {
			int k = rnd(0, t);
			int i = rnd(0, n / (1 << k) - 1);

			cout << op << " " << i << " " << k << "\n";
		}

		if(op == 3) {
			int k = t-1;
			int i = 0, j = 1;

			cout << op << " " << i << " " << j << " " << k << "\n";
		}

		if(op == 4) {
			int l = rnd(1, n), r = rnd(1, n);

			cout << op << " " << min(l, r) << " " << max(l, r) << "\n";
		}
	}

    return 0;
}
