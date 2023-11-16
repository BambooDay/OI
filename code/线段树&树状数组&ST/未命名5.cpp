#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
#define ls pos << 1
#define rs pos << 1|1
#define mid ((l+r)>>1)

using namespace std;
int a[N],n,node[N<<2],add[N<<2];
void push_up(int pos){
	node[pos] = node[ls] + node[rs];
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = a[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(pos); 
}
void push_down(int pos, int l, int r){
	node[ls] += (mid-l+1)*add[pos];
	node[rs] += (r-mid)*add[pos];
	add[ls] += add[pos];
	add[rs] += add[pos];
	add[pos] = 0;
} 
void upd(int pos, int l, int r, int x, int y, int z){
	if(x <= l && r <= y){
		node[pos] += (r-l+1)*z;
		add[pos] += z;
		return ; 
	}
	push_down(pos,l,r);
	if(x <= mid) upd(ls,l,mid,x,y,z);
	if(mid < y) upd(rs,mid+1,r,x,y,z);
	push_up(pos);
}
int ask(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return node[pos];
	}
	push_down(pos,l,r);
	int res = 0;
	if(x <= mid) res += ask(ls,l,mid,x,y);
	if(mid < y) res += ask(rs,mid+1,r,x,y);
	return res; 
}
signed main(){
	cin >> n;
	int m;
	cin >> m;
	for(int i =1 ;i <= n; i++) cin >> a[i];
	build(1,1,n);
	while(m--){
		int op,x,y,k;
		cin >> op;
		if( op == 1){
			cin >> x>> y >> k;
			upd(1,1,n,x,y,k);
		}else{
			cin >> x >> y;
			cout << ask(1,1,n,x,y) << endl;
		}
	} 
	return 0;
}
