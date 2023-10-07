#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for(register int i = (a); i <= (b); i++)
#define per(i, a, b) for(register int i = (a); i >= (b); i--)

using namespace std;

const int N = 5e1 + 5;

int n;
int sum[N][N];
char a[N][N];
int dp[N][N][N][N];

int main() {

    freopen("clear.in", "r", stdin);
    freopen("clear.out", "w", stdout);

    cin >> n;
    rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];

    rep(i, 1, n) rep(j, 1, n)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] == '#');

    auto query = [&](int l1, int r1, int l2, int r2) -> int {
        return sum[r1][r2] - sum[l1 - 1][r2] - sum[r1][l2 - 1] + sum[l1 - 1][l2 - 1];
    };

    memset(dp, 0x3f, sizeof(dp));

    rep(i, 1, n) rep(j, 1, n) rep(len, 1, min(n - i + 1, n - j + 1)) {
        int cnt = query(i, i + len - 1, j, j + len - 1);
        if(cnt == 0) dp[i][j][len][len] = 0;
        else dp[i][j][len][len] = len;
    }

    rep(iLen, 1, n) rep(jLen, 1, n) rep(i, 1, n - iLen + 1) rep(j, 1, n - jLen + 1) {
        int &res = dp[i][j][iLen][jLen];

        if(query(i, i + iLen - 1, j, j + jLen - 1) == 0) {
            dp[i][j][iLen][jLen] = 0;
            continue;
        }

        rep(j1, j, j + jLen - 2) {
            int jLen1 = j1 - j + 1, jLen2 = jLen - jLen1;
            res = min(res, dp[i][j][iLen][jLen1] + dp[i][j1 + 1][iLen][jLen2]);
        }

        rep(i1, i, i + iLen - 2) {
            int iLen1 = i1 - i + 1, iLen2 = iLen - iLen1;
            res = min(res, dp[i][j][iLen1][jLen] + dp[i1 + 1][j][iLen2][jLen]);
        }
    }

    cout << dp[1][1][n][n] << "\n";

    return 0;
}

