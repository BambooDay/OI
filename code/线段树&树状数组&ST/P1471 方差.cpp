#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1

using namespace std;
int n, m;
double a[N];
double sum[N << 2], pw[N<<2],tag[N<<2];
void push_up(int pos){
	sum[pos] = sum[ls(pos)] + sum[rs(pos)];
	pw[pos] = pw[ls(pos)] + pw[rs(pos)];
}
void push_down(int pos, int l, int r){
	int mid = (l+r) >> 1;
	tag[ls(pos)] += tag[pos];
	tag[rs(pos)] += tag[pos];
	pw[ls(pos)] += 2*tag[pos]*sum[ls(pos)] + (mid - l +1) * tag[pos]*tag[pos];
	pw[rs(pos)] += 2*tag[pos]*sum[rs(pos)] + (r - mid) * tag[pos]*tag[pos];
	sum[ls(pos)] += (mid - l +1) * tag[pos];
	sum[rs(pos)] += (r - mid)*tag[pos];
	tag[pos] = 0;
}
void build(int pos, int l, int r){
	if(l == r){
		sum[pos] = a[l];
		pw[pos] = a[l]*a[l];
		tag[pos] = 0;
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void update(int pos, int l, int r, int x, int y, double z){
	if(x <= l && y >= r){
		tag[pos] += z;
		pw[pos] += 2*z*sum[pos] + (r - l+1)*z*z;
		sum[pos] += (r - l +1) * z;
		return ; 
	}
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	if(mid >= x){
		update(ls(pos),l,mid,x,y,z);
	}
	if(mid < y){
		update(rs(pos),mid+1,r,x,y,z);
	}
	push_up(pos);
}
double query_a(int pos, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return sum[pos];
	}
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	double ans = 0;
	if(mid >= x){
		ans += query_a(ls(pos),l,mid,x,y);
	}
	if(mid < y){
		ans += query_a(rs(pos),mid+1,r,x,y);
	}
	return ans;
}
double query_b(int pos, int l, int r, int x, int y){
	if(x <= l && y >= r){
		return pw[pos];
	}
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	double ans = 0;
	if(mid >= x){
		ans += query_b(ls(pos),l,mid,x,y);
	}
	if(mid < y){
		ans += query_b(rs(pos),mid+1,r,x,y);
	}
	return ans;
}

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> a[i];
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x,y;
			double k;
			cin >> x >> y >> k;
			update(1,1,n, x, y, k);
		}
		if(op == 2){
			int x,y;
			cin >> x >> y;
			cout << fixed << setprecision(4) << query_a(1,1,n,x,y) * 1.0 / (y-x+1) << endl;
		}
		if(op == 3){
			int x, y;
			cin >> x >> y;
			double xx = query_a(1,1,n,x,y) * 1.0 / (y-x+1);
			xx = xx*xx;
			cout << fixed << setprecision(4) << -xx + query_b(1,1,n,x,y)*1.0 / (y-x+1) << endl;
		}
	}
	return 0;
}
