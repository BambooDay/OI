#include <bits/stdc++.h>
#define int long long
const int mod = 998244353; 
const int N = 3e5+10;
using namespace std;
char bg;
int ksm(int a, int b) {
	int ans = 1;
	while(b) {
		if(b&1) ans = ans *a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
int f(int n,int k) {
	if(n == 1) return 1;
	if(n&1) return (f(n-1,k)*ksm(2,k)+1)%mod;
	int ret = f(n/2,k);
	return (ret + ret*ksm(2,k*(n/2)))%mod;
}
int n,m;
int a[N];

int mi[N<<2],sum[N<<2];
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
void push_up(int pos) {
	mi[pos] = min(mi[ls(pos)],mi[rs(pos)]);
	sum[pos]=(sum[ls(pos)]+sum[rs(pos)])%mod;
}
void build(int pos,int l,int r) {
	if(l == r) {
		mi[pos] = a[l];
		sum[pos] = ksm(2,a[l]);
		return;
	}
	int mid = (l+r)>>1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void update(int pos,int l,int r,int p,int val) {
	if(l==r) {
		mi[pos] = val;
		sum[pos] = ksm(2,val);
		return;
	}
	int mid = (l+r)>>1;
	if(p <= mid) update(ls(pos),l,mid,p,val);
	else update(rs(pos),mid+1,r,p,val);
	push_up(pos);
}
int ask_mi(int pos,int l,int r,int x,int y) {
	if(x <= l && r <= y) return mi[pos];
	int mid = (l+r)>>1, ret = 1e9;
	if(x <= mid) ret = min(ret,ask_mi(ls(pos),l,mid,x,y));
	if(mid < y) ret = min(ret,ask_mi(rs(pos),mid+1,r,x,y));
	return ret;
}
int ask_sum(int pos,int l,int r,int x,int y) {
	if(x <= l && r <= y) return sum[pos];
	int mid = (l+r)>>1;
	int ret = 0;
	if(x <= mid) ret = (ret + ask_sum(ls(pos),l,mid,x,y))%mod;
	if(mid < y) ret = (ret + ask_sum(rs(pos),mid+1,r,x,y))%mod;
	return ret;
}
char ed;
signed main() {
//	freopen("1.in","r",stdin);
//	cout << (&bg-&ed)/1024.0/1024.0 << endl;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int x,y;
			cin >> x >> y;
			x ^= cnt;
			y ^= cnt;
			update(1,1,n,x,y);
		}else{
			int l,r,k;
			cin >> l >> r >> k;
			l ^= cnt,r ^= cnt,k ^= cnt;
			int mn = ask_mi(1,1,n,l,r);
			int su = ask_sum(1,1,n,l,r);
			if(su == f(r-l+1,k) * ksm(2,mn)%mod) {
				++cnt;
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
	return 0;
}

