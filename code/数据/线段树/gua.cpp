#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 3e5 + 5;

int n, m;
int a[N], tmp[N];

int main() {
	freopen("seg11.in","r",stdin);
	freopen("seg11.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];

    while(m--) {
        int op;
        cin >> op;

        if(op == 1) {
            int x, y;
            cin >> x >> y;

            a[x] = y;
        }

        if(op == 2) {
            int i, k;
            cin >> i >> k; k = (1 << k);

            reverse(seg(a, i * k + 1, (i + 1) * k));
        }

        if(op == 3) {
            int i, j, k;
            cin >> i >> j >> k; k = (1 << k);

            for(int p1 = i * k + 1, p2 = j * k + 1; p1 <= (i + 1) * k; p1++, p2++) {
                swap(a[p1], a[p2]);
            }
        }

        if(op == 4) {
            int l, r;
            cin >> l >> r;

            i64 sum = 0;
            rep(i, l, r) sum += a[i];

            cout << sum << "\n";
        }

        // rep(i, 1, n) cout << a[i] << " ";
        // cout << "\n";
    }

    return 0;
}
