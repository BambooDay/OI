#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> v[maxn];
int du[maxn], n, m;
int val[maxn], f[maxn];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> val[i], f[i] = 2e9 + 7;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        du[y]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(!du[i]) q.push(i);
    int ans = -2e9 - 7;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        ans = max(ans, val[now] - f[now]);
        f[now] = min(f[now], val[now]);
        for(int i = 0; i < v[now].size(); i++) {
            int to = v[now][i];
            f[to] = min(f[to], f[now]);
            du[to]--;
            if(!du[to]) q.push(to);
        }
    }
    cout << ans;
    return 0;
}