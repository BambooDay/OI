#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
const int N = 1e6+10;
using namespace std;
char bg;
int base[N];

inline int f(int n,int k) {
	if(n == 1) return 1;
	if(n&1) return (f(n-1,k)*base[k]+1)%mod;
	int ret = f(n/2,k);
	return (ret + ret*base[k*(n/2)])%mod;
}
int n,m;
int a[N];

int mi[N<<2],sum[N<<2];
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
inline void push_up(int pos) {
	mi[pos] = min(mi[ls(pos)],mi[rs(pos)]);
	sum[pos]=(sum[ls(pos)]+sum[rs(pos)])%mod;
}
inline void build(int pos,int l,int r) {
	if(l == r) {
		mi[pos] = a[l];
		sum[pos] = base[a[l]];
		return;
	}
	int mid = (l+r)>>1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
inline void update(int pos,int l,int r,int p,int val) {
	if(l==r) {
		mi[pos] = val;
		sum[pos] = base[val];
		return;
	}
	int mid = (l+r)>>1;
	if(p <= mid) update(ls(pos),l,mid,p,val);
	else update(rs(pos),mid+1,r,p,val);
	push_up(pos);
}
inline int ask_mi(int pos,int l,int r,int x,int y) {
	if(x <= l && r <= y) return mi[pos];
	int mid = (l+r)>>1, ret = 1e9;
	if(x <= mid) ret = min(ret,ask_mi(ls(pos),l,mid,x,y));
	if(mid < y) ret = min(ret,ask_mi(rs(pos),mid+1,r,x,y));
	return ret;
}
inline int ask_sum(int pos,int l,int r,int x,int y) {
	if(x <= l && r <= y) return sum[pos];
	int mid = (l+r)>>1;
	int ret = 0;
	if(x <= mid) ret = (ret + ask_sum(ls(pos),l,mid,x,y))%mod;
	if(mid < y) ret = (ret + ask_sum(rs(pos),mid+1,r,x,y))%mod;
	return ret;
}
char ed;
inline int read() {
	int s=0,w=1;
	char ch=getchar();

	while (ch<'0'||ch>'9') {
		if (ch=='-')  w=-w;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		s=(s<<1)+(s<<3)+(ch^'0');
		ch=getchar();
	}
	return s*w;
}
signed main() {
//	freopen("1.in","r",stdin);
//	cout << (&bg-&ed)/1024.0/1024.0 << endl;
	base[0] = 1;
	for(int i = 1; i <= 1e6; i++) base[i] = base[i-1]*2%mod;
	n = read(),m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1,1,n);
	for(int i = 1; i <= m; i++) {
		int op;
		cin >> op;
		if(op == 0) {
			int x,y;
//			cin >> x >> y;
			x = read(),y =read();
			update(1,1,n,x,y);
		} else {
			int l1=read(),r1=read(),l2=read(),r2=read();
//			cin >> l1 >> r1 >> l2 >> r2;
			int mn1 = ask_mi(1,1,n,l1,r1);
			int mn2 = ask_mi(1,1,n,l2,r2);
			int su1 = ask_sum(1,1,n,l1,r1);
			int su2 = ask_sum(1,1,n,l2,r2);
			if(mn1 > mn2) swap(mn1,mn2),swap(su1,su2);
			if(su1*base[mn2-mn1]%mod == su2) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}

