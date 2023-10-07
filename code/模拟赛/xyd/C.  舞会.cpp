
#include <bits/stdc++.h>
const int N = 200000 + 10;
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int n, l[N], r[N], sex[N], val[N];
bool out[N];
struct Node {
	int a, b, v;
	Node() {}
	Node(int _a, int _b, int _v): a(_a), b(_b), v(_v) {}
	bool friend operator < (const Node &x, const Node &y){
		return x.v == y.v ? x.a > y.a : x.v > y.v;
	}
} t;

inline int abs_(int a) {
	return a >= 0 ? a : -a;
}
priority_queue<Node> q;
int cnt = 0, ansa[N], ansb[N];
int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		char c;
//		c = read();
		cin >> c;
		sex[i] = c - '0';
		l[i] = i - 1;
		r[i] = i + 1;
	}
	for (int i = 1; i <= n; i++){
		val[i] =read();
	}
	for (int i = 1; i < n; i++){
		if (sex[i] != sex[i + 1]){
			q.push(Node(i, i + 1, abs_(val[i] - val[i + 1])));
		}
	}
	while (!q.empty()) {
		t = q.top();
		q.pop();
		if (out[t.a] || out[t.b]) continue;
		out[t.a] = out[t.b] = true;
		cnt++;
		ansa[cnt] = t.a;
		ansb[cnt] = t.b;
		int lx = l[t.a], rx = r[t.b];
		r[lx] = rx;
		l[rx] = lx;
		if (lx != 0 && rx != n + 1 && sex[lx] != sex[rx]) q.push(Node(lx, rx, abs_(val[lx] - val[rx])));
	}
	printf("%d\n",cnt);
	for (int i = 1; i <= cnt; i++){
		printf("%d %d\n",ansa[i],ansb[i]);
//		cout << ansa[i] << " " << ansb[i] << endl;
	}
	return 0;
}
