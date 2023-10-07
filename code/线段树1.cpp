#include<bits/stdc++.h>
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1 
const int N = 1e5+10;

using namespace std;
int node[N<<2],add[N<<2];
int a[N];
int n,m;
void push_up(int pos){
	node[pos] = node[ls(pos)] + node[rs(pos)];
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void push_down(int pos, int l, int r){
	add[ls(pos)] += add[pos];
	add[rs(pos)] += add[pos];
	int mid = (l+r) >> 1;
	node[ls(pos)] += (mid-l+1)*add[pos];
	node[rs(pos)] += (r - mid) * add[pos];
	add[pos] = 0; 
//	push_up(pos);//11111111
}
void update(int pos, int l, int r, int x, int y, int z){
//	cout << pos << endl; 
	if(x <= l && y >= r){
		add[pos] += z;
		node[pos] += (r-l+1) * z;
		return;
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
int query(int pos,int l,int r, int x, int y){
	if(x <= l && r<= y){
		return node[pos];
	}
	int res = 0;
	push_down(pos,l,r);
	int mid = (l + r)  >> 1;
	if(mid >= x){
		res += query(ls(pos),l,mid,x,y);
	}
	if(mid < y){
		res += query(rs(pos),mid+1,r,x,y);
	}
	return res;
}

signed main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, k;
			cin >> x >>y >> k;
			update(1,1,n,x,y,k);
		}else{
			int x,y;
			cin >> x >> y;
			cout << query(1,1,n,x,y) << endl;
		}
	}
	return 0;
}
