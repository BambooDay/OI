#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define LL long long

const int N = 50 + 5;
const int W = 5;
const int logT = 31;
const int K = 200 + 5;
const LL inf = 5e16;

int n, m, T, k;
int c[N];
struct activity {
	int t, x, y;
} act[K << 1];

struct matrix {
	LL e[N * W][N * W];
	int R, C;
	inline LL* operator [] (int p) {
		return e[p];
	}
	inline void set(LL v) {
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				e[i][j] = v;
	}
} A, B, P[logT];

inline matrix operator * (matrix a, matrix b) {
	matrix c;
	c.R = a.R, c.C = b.C;
	c.set(-inf);
	for (int k = 1; k <= a.C; k++)
		for (int i = 1; i <= a.R; i++)
			for (int j = 1; j <= b.C; j++)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
	return c;
}

void trans(matrix& B, int t) {
	if (!t) return;
	for (int i = 0; i < logT; i++)
		if ((t >> i) & 1)
			B = P[i] * B;
}

signed main() {

	cin >> n >> m >> T >> k;

	A.R = A.C = n * 5;
	A.set(-inf);

	for (int i = 1; i <= n; i++)
		for (int w = 1; w < W; w++)
			A[i + n * w][i + n * (w - 1)] = 0;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		A[v][u + n * (w - 1)] = c[u];
	}
	for (int i = 1; i <= k; i++)
		cin >> act[i].t >> act[i].x >> act[i].y;

	P[0] = A;
	for (int i = 1; i < logT; i++)
		P[i] = P[i - 1] * P[i - 1];
	B.R = n * 5, B.C = 1;
	B.set(-inf);
	B[1][1] = 0;

	sort(act + 1, act + 1 + k, [](activity & a, activity & b) {
		return a.t < b.t;
	});
	int curT = 0;
	for (int i = 1; i <= k; i++) {
		int gap = act[i].t - curT;
		trans(B, gap);
		B[act[i].x][1] += act[i].y;
		curT = act[i].t;
	}
	trans(B, T - curT);

	LL ans = B[1][1] + c[1];
	cout << (ans < 0 ? -1 : ans) << endl;
	return 0;
}
