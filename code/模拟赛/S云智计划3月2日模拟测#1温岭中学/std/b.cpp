#include <iostream>
#include <queue>

using namespace std;

const int N = 6005;

int n, m, dist[N], ways[N], len = 0x3f3f3f3f;
long long cnt = 0;
vector<int> G[N];

void gogo(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(ways, 0, sizeof ways);
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    ways[s] = 1;
    while (!que.empty()) {
        int x = que.front(); que.pop();
        for (int y : G[x]) {
            if (dist[x] == dist[y] || dist[x] + 1 == dist[y]) {
                int cyc = dist[x] + dist[y] + 1;
                long long c = ways[x] * ways[y];
                if (cyc < len) {
                    len = cyc;
                    cnt = c;
                }
                else if (cyc == len) {
                    cnt += c;
                }
            }
            if (dist[y] > dist[x] + 1) {
                dist[y] = dist[x] + 1;
                ways[y] = ways[x];
                que.push(y);
            }
            else if (dist[y] == dist[x] + 1) {
                ways[y] += ways[x];
            }
        }
    }   
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x) {
        gogo(x);
    }
    if (len % 2) {
        cnt /= len;
        cnt /= 2;
    }
    else {
        cnt /= len;
    }
    cout << cnt << "\n";
}
