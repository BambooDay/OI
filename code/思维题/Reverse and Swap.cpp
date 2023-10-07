#include <bits/stdc++.h>
#define int long long
#define Ls (p<<1)
#define Rs (p<<1|1)
#define ls (p<<1|rev[dep])
#define rs (p<<1|(rev[dep]^1))
#define mid ((l+r)>>1)
const int N = 20;
const int M = 3e5 + 10;
using namespace std;
int n, m, q, a[M], sum[M << 1], rev[N];
inline void pushup(int p) {
	sum[p] = sum[Ls] + sum[Rs];
}
void build(int p, int l, int r) {
	if (l == r) {
		sum[p] = a[l];
		return;
	}
	build(Ls, l, mid);
	build(Rs, mid + 1, r);
	pushup(p);
}
void update(int x, int p, int l, int r, int dep, int y) {
	if (l == r) {
		sum[p] = y;
		return;
	}
	if (x <= mid)update(x, ls, l, mid, dep - 1, y);
	if (x > mid) update(x, rs, mid + 1, r, dep - 1, y);
	pushup(p);
}
int query(int L, int R, int p, int l, int r, int dep) {
	if (L <= l && r <= R)
		return sum[p];
	int res = 0;
	if (L <= mid)res += query(L, R, ls, l, mid, dep - 1);
	if (R > mid) res += query(L, R, rs, mid + 1, r, dep - 1);
	return res;
}
inline void reverse(int x) {
	for (int i = 0; i <= x; i++)
		rev[i] ^= 1;
}
inline void Swap(int x) {
	rev[x + 1] ^= 1;
}
signed main() {
	cin >> n >> q;
	m = 1 << n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	build(1, 1, m);
	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int x, y;
			cin >> x >> y;
			update(x, 1, 1, m, n, y);
		}
		if (opt == 2) {
			int x ;
			cin >> x;
			reverse(x);
		}
		if (opt == 3) {
			int x;
			cin >> x;
			Swap(x);
		}
		if (opt == 4) {
			int l, r;
			cin >> l >> r;
			printf("%lld\n", query(l, r, 1, 1, m, n));
		}
	}
	return 0;
}
