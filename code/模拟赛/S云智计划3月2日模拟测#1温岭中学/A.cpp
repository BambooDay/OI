#include <bits/stdc++.h>
const int N = 6005;

using namespace std;

int n, m, dis[N], num[N], len = 1e9;
long long cnt = 0;
vector<int> e[N];

void gogo(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(num, 0, sizeof num);
	queue<int> que;
	que.push(s);
	dis[s] = 0;
	num[s] = 1;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int y : e[x]) {
			if (dis[x] == dis[y] || dis[x] + 1 == dis[y]) {
				int t = dis[x] + dis[y] + 1;
				long long c = num[x] * num[y];
				if (t < len) {
					len = t;
					cnt = c;
				} else if (t == len) {
					cnt += c;
				}
			}
			if (dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				num[y] = num[x];
				que.push(y);
			} else if (dis[y] == dis[x] + 1) {
				num[y] += num[x];
			}
		}
	}
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int x = 1; x <= n; ++x) {
		gogo(x);
	}
	if (len % 2) {
		cnt /= len;
		cnt /= 2;
	} else {
		cnt /= len;
	}
	cout << cnt << "\n";
}
