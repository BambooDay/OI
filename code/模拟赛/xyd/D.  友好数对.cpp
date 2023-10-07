#include<bits/stdc++.h>

using namespace std;

struct question {
	int l, r, x;
	int ans;
} ques[39];
bool cmp(question x, question y) {
	return x.r < y.r;
}
int t;
int l, r;
int get_len(int x) {
	int u = 0;
	while (x) {
		x /= 10;
		u++;
	}
	return u;
}
bool cmp1(question x, question y) {
	return x.x < y.x;
}
struct Node {
	int s, fa, son, ma, w;
} a[2000009];
bool check(int x) {
	while (x) {
		if (x == 1) return 1;
		if (x % 10 != 0) return 0;
		x /= 10;
	}
}
void add(int x) {
	if (check(x)) {
		a[x].s = 1;
		a[x].w = a[x].ma = 0;
		return;
	}
	int ll = get_len(x);
	int v = x;
	int ma = -1;
	int mn = 1;
	for (int i = 1; i < ll; i++)
		mn *= 10;
	for (int j = 1; j < ll; j++) {
		int u = x % 10;
		x /= 10;
		for (int j = 1; j < ll; j++)
			u *= 10;
		x += u;
		if (x < v && x >= mn) {
			if (ma == -1 || x > ma) ma = x;
		}
	}
	a[v].w = a[v - 1].w;
	if (ma == -1) a[v].s = a[v].ma = 1;
	else {
		a[v].w += a[ma].s;
		a[v].son = ma;
		a[ma].fa = v;
		a[v].s = a[ma].s + 1;
		a[ma].ma = a[v].s;
		int i = ma;
		while (a[i].son) {
			i = a[i].son;
			a[i].ma = a[v].s;
		}
	}
}
int len = 0;
int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> ques[i].l>> ques[i].r;
		ques[i].x = i;
	}
	sort(ques + 1, ques + t + 1, cmp);
	for (int j = 1; j <= t; j++) {
		while (len < ques[j].r){
			add(++len);
		} 
		ques[j].ans = a[ques[j].r].w;
		int mn = 1, ll = get_len(ques[j].l);
		for (int i = 1; i < ll; i++){
			mn *= 10;
		}
		for (int i = ques[j].l - 1; i >= mn; i--) {
			if (a[i].fa == 0){
				ques[j].ans -= (a[i].s - 1) * a[i].s / 2;
			} else if (a[i].fa >= ques[j].l) {
				ques[j].ans -= (a[i].ma - 1) * a[i].ma / 2;
				ques[j].ans += (a[i].ma - a[i].s - 1) * (a[i].ma - a[i].s) / 2;
			}
		}
	}
	sort(ques + 1, ques + t + 1, cmp1);
	for (int i = 1; i <= t; i++){
		cout << ques[i].ans << endl;
	}
	return 0;
}
