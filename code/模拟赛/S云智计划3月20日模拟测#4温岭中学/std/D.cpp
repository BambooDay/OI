#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
    x = 0;
    short f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -1;
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    x *= f;
    return;
}
#define ll long long
const int N = 1e6 + 5;
ll x[N], a[N];
int n, k, t;
bool check(ll v) {
    for (int i = 1; i <= n; ++i) a[i] = x[i] - 2ll * v * i * t;
    if (a[1] < a[n])
        return 0;
    int L = k, R = k;
    for (int i = 1; i <= k - 1; ++i)
        if (a[i] > a[L])
            L = i;
    for (int i = k + 1; i <= n; ++i)
        if (a[i] <= a[R])
            R = i;
    int l = k, r = k;
    while (l != L || r != R) {
        bool flag = 0;
        int tl = l, tr = r;
        while (tl > L && a[tl - 1] >= a[r])
            if (a[--tl] >= a[l])
                break;
        if (tl < l && a[tl] >= a[l])
            flag = 1, l = tl;
        while (tr < R && a[tr + 1] <= a[l])
            if (a[++tr] <= a[r])
                break;
        if (tr > r && a[tr] <= a[r])
            flag = 1, r = tr;
        if (!flag)
            return 0;
    }
    l = 1, r = n;
    while (l != L || r != R) {
        bool flag = 0;
        int tl = l, tr = r;
        while (tl < L && a[tl + 1] >= a[r])
            if (a[++tl] >= a[l])
                break;
        if (tl > l && a[tl] >= a[l])
            flag = 1, l = tl;
        while (tr > R && a[tr - 1] <= a[l])
            if (a[--tr] <= a[r])
                break;
        if (tr < r && a[tr] <= a[r])
            flag = 1, r = tr;
        if (!flag)
            return 0;
    }
    return 1;
}
int main() {
    read(n), read(k), read(t);
    for (int i = 1; i <= n; ++i) read(x[i]);
    ll l = 0, r = 1e9, ans = r;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}