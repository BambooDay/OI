#include<bits/stdc++.h>

using namespace std;

#define N 200005
typedef unsigned long long ll;

int n;

ll K, a[N];

bool flag = 0;

ll mul(ll x, ll y) {
	ll ans = 0;
	while(y) {
		if(y & 1) ans += x, ans = min(ans, K);
		x += x, x = min(x, K);
		y >>= 1;
	}
	return ans;
}

struct Matrix {
	int n, m;
	ll a[25][25];
	void clear(int x, int y) {
		n = x, m = y;
		memset(a, 0, sizeof(a));
	}

	Matrix operator * (const Matrix &o) const {
		Matrix ans;
		ans.clear(n, o.m);
		for(int i = 1; i <= ans.n; i++)
			for(int j = 1; j <= ans.m; j++)
				for(int k = 1; k <= m; k++) {
					ans.a[i][j] += mul(a[i][k], o.a[k][j]);
					ans.a[i][j] = min(ans.a[i][j], K);
				}
		return ans;
	}

	Matrix operator ^ (const ll &k) const {
		Matrix ans;
		ans.clear(n, m);
		for(int i = 1; i <= min(ans.n, ans.m); i++) ans.a[i][i] = 1;
		Matrix base = *this;
		ll x = k;
		while(x) {
			if(x & 1) ans = ans * base;
			base = base * base;
			x >>= 1;
		}
		return ans;
	}

	void print() {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
};

int main() {
	scanf("%d%lld", &n, &K);
	bool is1 = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if(a[i] >= K) {
			cout << 0 << endl;
			return 0;
		}
		if(a[i]) is1 = 1;
		if(a[i] == 0 && !is1) i--, n--;
	}
	if(n > 10) {
		int cnt = 0;
		while(1) {
			cnt++;
			for(int i = 1; i <= n; i++) {
				a[i] += a[i - 1];
				if(a[i] >= K || a[i] < 0) {
					cout << cnt << endl;
					return 0;
				}
			}
		}
	}
	Matrix b;
	b.clear(n, 1);
	for(int i = 1; i <= n; i++) b.a[i][1] = a[i];
	Matrix c;
	c.clear(n, n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) c.a[i][j] = 1;
	ll l = 1, r = 1000000000000000000, ans = 0;
	while(l <= r) {
		ll mid = l + r >> 1;
		bool flag = 0;
		Matrix tmp = (c ^ mid) * b;
		for(int i = 1; i <= tmp.n; i++)
			for(int j = 1; j <= tmp.m; j++) flag = max(flag, (tmp.a[i][j] >= K || tmp.a[i][j] < 0));
		if(flag) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}

