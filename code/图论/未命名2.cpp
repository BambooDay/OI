#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
using namespace std;
typedef long long ll;

int read() {
	int X = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
	return X;
}

const int N = 250 + 10, K = 200 + 10;

int n, m, T, k, c[N];
int id[N][6], tot;

struct festival {
	int t, x, y;
} t[K];
bool operator <(festival a, festival b) {
	return a.t < b.t;
}

struct Matrix {
	ll s[N][N];
	Matrix() {
		memset(s, 0xc0, sizeof(s));
	}
	ll* operator [](int i) {
		return s[i];
	}
} Q[31];
ll A[N];
Matrix operator *(Matrix a, Matrix b) {
	Matrix c;
	for (int i = 1; i <= tot; ++i)
		for (int k = 1; k <= tot; ++k) {
			if (a[i][k] < 0) continue;
			for (int j = 1; j <= tot; ++j)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
		}
	return c;
}
void Mul(Matrix Q) {
	static ll B[N];
	for (int i = 1; i <= tot; ++i) B[i] = -4e18;
	for (int k = 1; k <= tot; ++k) {
		if (A[k] < 0) continue;
		for (int j = 1; j <= tot; ++j)
			B[j] = max(B[j], A[k] + Q[k][j]);
	}
	for (int i = 1; i <= tot; ++i) A[i] = B[i];
}

int main() {
	tot = n = read(), m = read(), T = read(), k = read();
	for (int i = 1; i <= n; ++i) c[i] = read();
	for (int i = 1; i <= n; ++i) id[i][0] = i;
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		for (int j = 1; j < w; ++j) if (!id[u][j]) id[u][j] = ++tot;
		for (int j = 1; j < w; ++j) Q[0][id[u][j - 1]][id[u][j]] = 0;
		Q[0][id[u][w - 1]][v] = c[v];
	}
	for (int i = 1; i <= k; ++i) t[i] = (festival) {read(), read(), read()};
	sort(t + 1, t + k + 1);
	t[0] = (festival) {0, 0, 0}, t[k + 1] = (festival) {T, 0, 0};
	for (int i = 1; i <= 30; ++i) Q[i] = Q[i - 1] * Q[i - 1];
	for (int i = 2; i <= tot; ++i) A[i] = -4e18;
	A[1] = c[1];
	for (int i = 1; i <= k + 1; ++i) {
		int dt = t[i].t - t[i - 1].t;
		for (int j = 30; ~j; --j) if (dt & (1 << j)) Mul(Q[j]);
		A[t[i].x] += t[i].y;
	}
	if (A[1] < 0) puts("-1");
	else printf("%lld\n", A[1]);
	return 0;
}
