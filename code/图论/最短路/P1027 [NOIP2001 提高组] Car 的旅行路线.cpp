#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, t, A, B, st, ed;
int cityst[10];
int cityed[10];
int id = 0;
int T[110];
struct ss {
	int x, y, c;
} node[N];

struct nde {
	int to, nxt;
	double v;
} edge[N];
int first[N], ct = 0;

void add(int a, int b, double c) {
	edge[++ct].to = b;
	edge[ct].v = c;
	edge[ct].nxt = first[a];
	first[a] = ct;
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void forth(int x1, int y1, int x2, int y2, int x3, int y3, int i) {
	int x4, y4;
	int ab = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2),
	    ac = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3),
	    bc = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
	if (ab + ac == bc) x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
	if (ab + bc == ac) x4 = x1 + x3 - x2, y4 = y1 + y3 - y2;
	if (ac + bc == ab) x4 = x1 + x2 - x3, y4 = y1 + y2 - y3;
	node[++id].x = x1, node[id].y = y1, node[id].c = i;
	if (i == A) cityst[1] = id;
	if (i == B) cityed[1] = id;
	node[++id].x = x2, node[id].y = y2, node[id].c = i;
	if (i == A) cityst[2] = id;
	if (i == B) cityed[2] = id;
	node[++id].x = x3, node[id].y = y3, node[id].c = i;
	if (i == A) cityst[3] = id;
	if (i == B) cityed[3] = id;
	node[++id].x = x4, node[id].y = y4, node[id].c = i;
	if (i == A) cityst[4] = id;
	if (i == B) cityed[4] = id;
}

double dist[N];
bool f[N];
void dijkstra(int s) {
	memset(f, 0, sizeof f);
	for (int i = 0; i <= ct + 10; i++) dist[i] = 1e9 + 10;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > Q;
	dist[s] = 0;
	Q.push(make_pair(0, s));
	while (!Q.empty()) {
		int t = Q.top().second;
		Q.pop();
//		cout << t << endl;
		if (f[t]) continue;
		f[t] = 1;
		for (int i = first[t]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if (dist[y] > dist[t] + edge[i].v) {
				dist[y] = dist[t] + edge[i].v;
				Q.push(make_pair(dist[y], y));
			}
		}
	}
	return;
}

void dian() {
	A = ++id;
	for (int i = 1; i <= 4; i++) {
		int k = cityst[i];
		add(A, k, 0);
	}
	B = ++id;
	for (int i = 1; i <= 4; i++) {
		int k = cityed[i];
		add(k, B, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--){	
		cin >> n >> t >> A >> B;
		for (int i = 1; i <= n; i++) {
			int x1, x2, x3, y1, y2, y3;
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> T[i];
			forth(x1, y1, x2, y2, x3, y3, i);
		}
		for (int i = 1; i <= id; i++)
			for (int j = i + 1; j <= id; j++) {
				int x1 = node[i].x, y1 = node[i].y, c1 = node[i].c;
				int x2 = node[j].x, y2 = node[j].y, c2 = node[j].c;
				if (c1 == c2) {
					double d = distance(x1, y1, x2, y2) * T[c1];
					add(i, j, d), add(j, i, d);
				} else {
					double d = distance(x1, y1, x2, y2) * t;
					add(i, j, d), add(j, i, d);
				}
			}
		dian();
		dijkstra(A);
		printf("%.1f\n", dist[B]);
	}
	return 0;
}
