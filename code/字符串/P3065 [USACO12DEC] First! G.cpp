#include <bits/stdc++.h>
using namespace std;

const int N = 3e6;

int n, now, ans, flag[N / 10];
string str[N / 10];
int e1[N], ch[N], ne1[N], h1[N], id, tot = 1;
int t[N], cant;
int e[2000], ne[2000], h[40], idx;
int vis[2000], can[40];

void add1(int a, int b, int c) {
	e1[ ++ id] = b, ch[id] = c, ne1[id] = h1[a], h1[a] = id;
}

void add(int a, int b) {
	e[ ++ idx] = b, ne[idx] = h[a], h[a] = idx;
}

void dfs1(int x, string s, int p) {
	if(p == s.size()) {
		t[x] = 1;
		return;
	}
	bool f = true;
	for(int i = h1[x] ; i ; i = ne1[i]) {
		if(ch[i] == s[p] - 'a' + 1) {
			f = false;
			dfs1(e1[i], s, p + 1);
		}
	}
	if(f) {
		add1(x, ++ tot, s[p] - 'a' + 1);
		dfs1(tot, s, p + 1);
	}
}

void dfs2(int x, string s, int p) {
	if(p == s.size()) return;
	if(t[x]) {
		cant = 1;
		return;
	}
	int nt = 0, st = s[p] - 'a' + 1;
	for(int i = h1[x] ; i ; i = ne1[i]) {
		if(ch[i] == st) nt = e1[i];
		else if(vis[st * 26 + ch[i]] != now) {
			add(st, ch[i]);
			vis[st * 26 + ch[i]] = now;
		}
	}
	dfs2(nt, s, p + 1);
}

bool dfs3(int x) {
	if(can[x]) return true;
	can[x] = 1;
	bool f = false;
	for(int i = h[x] ; i ; i = ne[i]) {
		int y = e[i];
		f |= dfs3(y);
	}
	can[x] = 0;
	return f;
}

int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> str[i];
		dfs1(1, str[i], 0);
	}

	for(now = 1 ; now <= n ; now ++) {
		memset(h, 0, sizeof h);
		idx = cant = 0;
		dfs2(1, str[now], 0);
		if(cant) continue;

		bool f = true;
		for(int i = 1 ; i <= 26 ; i ++) {
			if(dfs3(i)) {
				f = false;
				break;
			}
		}
		if(f) ans ++, flag[now] = 1;
	}

	cout << ans << "\n";
	for(int i = 1 ; i <= n ; i ++)
		if(flag[i]) cout << str[i] << "\n";

	return 0;
}
