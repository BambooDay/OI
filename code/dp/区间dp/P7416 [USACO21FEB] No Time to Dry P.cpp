#include<cstdio>
#include<algorithm>
#include <iostream>
#define N 200005
using namespace std;
struct seg {
	int mn, val, lazy;
} tree[N << 2];
int n, q, l, r, t[N], pre[N], a[N << 1], ans[N], qo[N][3], last[N], ls[N];
void build(int now, int l, int r) {
	if (l == r) {
		tree[now].mn = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(now << 1, l, mid);
	build(now << 1 | 1, mid + 1, r);
	tree[now].mn = min(tree[now << 1].mn, tree[now << 1 | 1].mn);
}
int getmin(int now, int l, int r, int p, int q) {
	if (p > q) return 2147483647;
	if (l >= p && r <= q) return tree[now].mn;
	int mid = (l + r) >> 1, res = 2147483647;
	if (p <= mid) res = min(res, getmin(now << 1, l, mid, p, q));
	if (q > mid) res = min(res, getmin(now << 1 | 1, mid + 1, r, p, q));
	return res;
}
void pushup(int now, int len) {
	if (tree[now].lazy) {
		tree[now << 1].lazy += tree[now].lazy;
		tree[now << 1 | 1].lazy += tree[now].lazy;
		tree[now << 1].val += tree[now].lazy * (len - (len >> 1));
		tree[now << 1 | 1].val += tree[now].lazy * (len >> 1);
		tree[now].lazy = 0;
	}
}
void modify(int now, int l, int r, int p, int q, int v) {
	if (l >= p && r <= q) {
		tree[now].lazy += v;
		tree[now].val += v * (r - l + 1);
		return;
	}
	pushup(now, r - l + 1);
	int mid = (l + r) >> 1;
	if (p <= mid) modify(now << 1, l, mid, p, q, v);
	if (q > mid) modify(now << 1 | 1, mid + 1, r, p, q, v);
	tree[now].val = tree[now << 1].val + tree[now << 1 | 1].val;
}
int query(int now, int l, int r, int p) {
	if (l == r) return tree[now].val;
	pushup(now, r - l + 1);
	int mid = (l + r) >> 1;
	if (p <= mid) return query(now << 1, l, mid, p);
	else return query(now << 1 | 1, mid + 1, r, p);
}
//struct question{
//	int id, l, r;
//}ques[N];
//bool cmp(question x, question y){
//	return x.r < y.r;
//}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		pre[i] = t[a[i]];
		t[a[i]] = i;
	}
	for (int i = 1; i <= q; ++i) {
//		cin >>ques[i].l >> ques[i].r;
//		ques[i].id = i;		 
		scanf("%d%d", &l, &r);
		last[i] = ls[r];
		ls[r] = i;
		qo[i][1] = i;
		qo[i][2] = l;
	}
//	sort(ques+1,ques+1+q,cmp);
	for (int i = 1; i <= n; ++i) {
		if (getmin(1, 1, n, pre[i] + 1, i - 1) < a[i]) modify(1, 1, n, 1, i, 1);
		else modify(1, 1, n, pre[i] + 1, i, 1);
		for (int j = ls[i]; j; j = last[j])
			ans[qo[j][1]] = query(1, 1, n, qo[j][2]);
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
