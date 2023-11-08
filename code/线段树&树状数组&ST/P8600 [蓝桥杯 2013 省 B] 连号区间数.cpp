#include <bits/stdc++.h>
const int N =  5e4+10;
#define ls (pos<<1)
#define rs (pos<<1|1)
using namespace std;

int n,a[N<<2];

struct tree {
	int l,r;
	int tag,val,mi;
} node[N<<2];

inline void pushup(int pos) {
	node[pos].mi=min(node[ls].mi,node[rs].mi);
	node[pos].val=(node[pos].mi==node[ls].mi?node[ls].val:0)+(node[pos].mi==node[rs].mi?node[rs].val:0);
}

inline void build(int pos,int l,int r) {
	node[pos].l=l;
	node[pos].r=r;
	if (l==r) {
		node[pos].mi=l;
		node[pos].val=1;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(pos);
}

inline void push_down(int pos) {
	if (node[pos].tag) {
		node[ls].tag+=node[pos].tag;
		node[rs].tag+=node[pos].tag;
		node[ls].mi+=node[pos].tag;
		node[rs].mi+=node[pos].tag;
		node[pos].tag=0;
	}
}

inline void update(int pos,int l,int r,int val) {
	if (l<=node[pos].l && node[pos].r<=r) {
		node[pos].tag+=val;
		node[pos].mi+=val;
		return;
	}
	push_down(pos);
	int mid=(node[pos].l+node[pos].r)>>1;
	if (r<=mid)
		update(ls,l,r,val);
	else if (l>mid)
		update(rs,l,r,val);
	else {
		update(ls,l,mid,val);
		update(rs,mid+1,r,val);
	}
	pushup(pos);
}

int st1[N],st2[N],top1,top2;

long long ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	for (int i = 1; i <= n; i++) {
		int p = i;
		while (top1 && a[i]<a[st1[top1]]) {
			update(1,st1[top1-1]+1,p-1,a[st1[top1]]-a[i]);
			p = st1[top1];
			top1--;
		}
		p = i;
		while (top2 && a[i] > a[st2[top2]]) {
			update(1,st2[top2-1]+1,p-1,-a[st2[top2]]+a[i]);
			p = st2[top2];
			top2--;
		}
		st1[++top1]=st2[++top2]=i;
		ans += node[1].val;
	}
	cout << ans << endl;
	return 0;
}

