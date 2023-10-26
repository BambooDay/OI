#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
using namespace std;
int n,a[N],m;
int node[N<<2],add[N<<2];
void push_up(int pos){
	node[pos] = node[ls(pos)] + node[rs(pos)];
}
void push_down(int pos, int l, int r){
	int mid = (l+r) >> 1;
	node[ls(pos)] += add[pos] * (mid - l + 1);
	node[rs(pos)] += add[pos] * (r-mid);
	add[ls(pos)] += add[pos];
	add[rs(pos)] += add[pos];
	add[pos] = 0;
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = a[l];
		add[pos] = 0;
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void update(int pos, int l, int r, int x, int y, int z){
	if(l >= x && r <= y){
		node[pos] += (r-l+1)*z;
		add[pos] += z;
		return;
	}
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	if(mid >= x){
		update(ls(pos),l,mid,x,y,z);
	}
	if(y > mid){
		update(rs(pos),mid+1,r,x,y,z);
	}
	push_up(pos);
}
int query(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y) return node[pos];
	push_down(pos,l,r);
	int mid = (l+r) >> 1;
	int ans = 0;
	if(mid >= x){
		ans += query(ls(pos),l,mid,x,y);
	}
	if(mid < y){
		ans += query(rs(pos),mid+1,r,x,y);
	}
//	push_up(pos);
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
			int x,y,z;
			cin >> x >> y >> z;
			update(1,1,n,x,y,z);
		}else{
			int x, y;
			cin >> x >> y;
			cout << query(1,1,n,x,y) << endl;
		}
	}
	return 0;
}
