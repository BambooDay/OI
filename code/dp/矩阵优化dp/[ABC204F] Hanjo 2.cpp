#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = (1 << 6) + 5;
const int mod = 998244353;

int cnt[N];
int h, w;
int ss;

struct Matrix {
    int n, m, d[105][105];
    void clear() {
        memset(d, 0, sizeof(d));
    }

    void identity() {
        clear();
        for (int i = 0; i < n; ++i) {
            d[i][i] = 1;
        }
    }

    Matrix(int n, int m) : n(n), m(m) {}
};

Matrix mul(const Matrix &a, const Matrix &b) {
    Matrix c(a.n, b.m);
    c.clear();
    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < b.m; ++j) {
    		for (int k = 0; k < a.m; ++k) {
                c.d[i][j] += (a.d[i][k] * b.d[k][j]) % mod;
                c.d[i][j] %= mod;
            }
        }
    }
    return c;
}

Matrix pow(Matrix &a, int p) {
    Matrix result(a.n, a.n);
    result.identity();
    Matrix base = a;
    while (p) {
        if (p & 1) {
            result = mul(result, base);
        }
        base = mul(base, base);
        p >>= 1;
    }
    return result;
}


void dfs(int step, int last, int status) {
    if (step == h) {
        if (last == 0) {
            cnt[status]++;
        }
    } else {
        if (last == 1) {
            dfs(step + 1, 0, status << 1 | 1);
        } else {
            dfs(step + 1, 0, status << 1);
            dfs(step + 1, 0, status << 1 | 1);
            dfs(step + 1, 1, status << 1 | 1);
        }
    }
}

Matrix init() {
    Matrix r(ss, ss);
    for (int i = 0; i < ss; ++i) {
        int s = i ^ ((1 << h) - 1);
        for (int j = 0; j < ss; ++j) {
            if ((s & j) == s) {
                r.d[i][j] = cnt[i & j];
            }
        }
    }
    return r;
}

signed main() {
    cin >> h >> w;
    ss = 1 << h;
    dfs(0, 0, 0);
    Matrix t = init();
    t = pow(t, w - 1);
    int ans = 0;
    for (int i = 0; i < ss; ++i) {
        ans = (ans + cnt[i] * t.d[i][ss - 1] % mod) % mod;
    }
    cout << ans;
    return 0;
}
