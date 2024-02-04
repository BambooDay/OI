#include<bits/stdc++.h>
const int N = 5e5+10;
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)

using namespace std;
struct Node{
	int sum,val;
	int maxpre,maxsuf;
	friend Node operator + (Node x, Node y){
		Node z;
		z.sum = x.sum + y.sum;
		z.maxpre = max(x.maxpre,x.sum + y.maxpre);
		z.maxsuf = max(y.maxsuf,y.sum + x.maxsuf);
		z.val = max(max(x.val,y.val),x.maxsuf+y.maxpre);
		return z;
	}
}node[N<<2];
void push_up(int pos){
	node[pos] = node[ls]+node[rs];
}
int a[N];
void build(int pos, int l, int r){
	if(l == r){
		node[pos].sum = node[pos].maxpre = node[pos].maxsuf = node[pos].val = a[l];
//		cout << pos << " " << l << " " << r << endl;
//		cout << node[pos].sum << " " << node[pos].val << " " << node[pos].maxpre << " " << node[pos].maxsuf << endl;
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(pos);
}
void modify(int pos, int l, int r, int x, int y){
	if(l == r){
		node[pos].sum = y;
		node[pos].val = y;
		node[pos].maxpre = y;
		node[pos].maxsuf = y;	
		return;
	}
	if(mid >= x) modify(ls,l,mid,x,y);
	else modify(rs,mid+1,r,x,y);
	push_up(pos);
}
Node query(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
//		cout << pos << endl;
//		cout << l << " " << r << " " << x << " " << y << endl;
//		cout << node[pos].sum << " " << node[pos].val << " " << node[pos].maxpre << " " << node[pos].maxsuf << endl;
		return node[pos];
	}
	if(mid >= y) return query(ls,l,mid,x,y);
	if(mid < x) return query(rs,mid+1,r,x,y);
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
int n,m;

signed main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
//	int pos = 8;
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int a,b;
			cin >> a >> b;
			if(a > b) swap(a,b);
			cout << query(1,1,n,a,b).val << endl; 
		}else{
			int x,y;
			cin >> x >> y;
			modify(1,1,n,x,y);
		}
	}	
	return 0;
}

