#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int fa[1000010];
int n, m, need;
struct node {
	int s, t, v, c;
} e[1000010];

bool cmp(node a, node b) {
	if (a.v == b.v) return a.c < b.c;
	else return a.v < b.v;
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int sum, ans, temp;
int cnt = 0;
void kruskal() {
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; cnt != n - 1; i++) {
		int xx = find(e[i].s), yy = find(e[i].t);
		if (xx == yy) continue;
		if (xx != yy) {
			cnt++;
			fa[xx] = yy;
			if (e[i].c == 0) temp++;
			sum += e[i].v;
		}
	}
}

int main() {
	cin >> n >> m >> need;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].s >> e[i].t >> e[i].v >> e[i].c;
		e[i].s++, e[i].t++;
	}
	int l = -111, r = 111;
	while (l <= r) {
		int mid = (l + r) >> 1;
		for (int i = 1; i <= m; i++){
			if (e[i].c == 0) e[i].v += mid;
		}	
		for (int i = 1; i <= n + 1; i++) fa[i] = i;
		sum = 0, cnt = 0, temp = 0;
		kruskal();
		if (temp >= need) {
			l = mid + 1;
			ans = sum - need * mid;
		} else r = mid - 1;
		for (int i = 1; i <= m; i++) {
			if (e[i].c == 0) e[i].v -= mid;
		}
	}
	cout << ans;
	return 0;
}
