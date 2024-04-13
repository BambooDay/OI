#include <bits/stdc++.h>
using namespace std;
char buf[1000000], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++)
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
char out[1 << 23], *pout = out, *eout = out + (1 << 23);
inline void flush() { fwrite(out, 1, pout - out, stdout), pout = out; }
inline void pc(char c) {
    pout == eout && (fwrite(out, 1, 1 << 23, stdout), pout = out);
    (*pout++) = c;
}
template <typename T>
inline void print(T x) {
    static int stk[35], top;
    if (x < 0)
        pc('-'), x = -x;
    if (x == 0)
        pc('0');
    while (x) stk[++top] = x % 10, x /= 10;
    while (top) pc(stk[top--] + '0');
    pc('\n');
}
const int N = 5e5 + 5;
#define ll long long
struct node {
    int v, w, nxt;
} e[N * 2];
int head[N], cnt = 1;
void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}
struct Tree {
    int rt;
    int son[N], f[N][20], rk[N];
    int p[N], tot;
    ll ans[N], len[N], dis[N], maxd[N];
    void dfs1(int u, int fa) {
        if (dis[u] > dis[rt])
            rt = u;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (v == fa)
                continue;
            dis[v] = dis[u] + e[i].w;
            dfs1(v, u);
        }
    }
    void dfs2(int u, int fa) {
        f[u][0] = fa;
        for (int k = 1; k <= 19; ++k) f[u][k] = f[f[u][k - 1]][k - 1];
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (v == fa)
                continue;
            dis[v] = dis[u] + w;
            dfs2(v, u);
            if (w + maxd[v] > maxd[u])
                maxd[u] = maxd[v] + w, son[u] = v;
        }
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if (v == fa || v == son[u])
                continue;
            p[++tot] = v;
            len[v] = maxd[v] + e[i].w;
        }
        if (!fa)
            p[++tot] = u, len[u] = maxd[u];
    }
    void init(int x) {
        dfs1(x, 0);
        dis[rt] = 0;
        dfs2(rt, 0);
        sort(p + 1, p + tot + 1, [&](int x, int y) { return len[x] > len[y]; });
        for (int i = 1; i <= tot; ++i) {
            ans[i] = ans[i - 1] + len[p[i]];
            for (int u = p[i]; u; u = son[u]) rk[u] = i;
        }
    }
    ll ask(int x, int y, int tp) {
        ll w = maxd[x] + dis[x] + ans[y];
        for (int k = 19; k >= 0; --k)
            if (rk[f[x][k]] > y)
                x = f[x][k];
        return w - dis[f[x][0]] - (tp ? maxd[f[x][0]] : 0);
    }
    ll query(int x, int y) {
        y = 2 * y - 1;
        return rk[x] > y ? max(ask(x, y - 1, 0), ask(x, y, 1)) : ans[min(tot, y)];
    }
} A, B;
int n, m;
int main() {
    read(n);
    read(m);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        read(u), read(v), read(w);
        add(u, v, w), add(v, u, w);
    }
    A.init(1);
    B.init(A.rt);
    while (m--) {
        int a, k;
        read(a), read(k);
        print(max(A.query(a, k), B.query(a, k)));
    }
    flush();
    return 0;
}