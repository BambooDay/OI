#include <bits/stdc++.h>
#define int long long
const int N = 20;

using namespace std;
struct Node{
	int sum;
	int ls, rs,fa;
	bool rvs;
}node[1<<N];
int a[1<<N],n,m;
void push_up(int pos){
	node[pos].sum = node[node[pos].ls].sum + node[node[pos].rs].sum;
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos].sum = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	node[pos].ls = pos << 1;
	node[pos].rs = pos << 1 | 1;
	build(pos<<1,l,mid);
	build(pos<<1|1, mid+1, r);
	node[node[pos].ls].fa = node[node[pos].rs].fa = pos;
	push_up(pos);
}
void push_down(int pos){
	if(node[pos].rvs){
		swap(node[pos].ls, node[pos].rs);
		node[node[pos].ls].rvs ^= 1;
		node[node[pos].rs].rvs ^= 1;
		node[pos].rvs = 0;
	}
}
void modify(int pos, int l, int r,int x, int y){
	if(l == r){
		node[pos].sum = y;
		return;
	}
	push_down(pos);
	int mid = (l+r) >> 1;
	if(x <= mid){
		modify(node[pos].ls,l,mid,x,y);
	}else{
		modify(node[pos].rs, mid+1, r, x, y);
	}
	push_up(pos);
}
void reverse(int pos, int l, int r, int x, int y){
	if(l == x && r == y){
		node[pos].rvs ^= 1;
		return;
	}
	push_down(pos);
	int mid = (l+r) >> 1;
	if(x <= mid){
		reverse(node[pos].ls,l,mid,x,y);
	}else{
		reverse(node[pos].rs,mid+1,r,x,y);
	}
}
void find(int pos, int l, int r, int x, int y,int &fa, int &son){
	if(l == x && r == y){
		return;
	}
	push_down(pos);
	int mid = (l+r) >> 1;
	fa = pos;
	if(x <= mid){
		son = 0;
		find(node[pos].ls,l,mid,x,y,fa,son);
	}else{
		son = 1;
		find(node[pos].rs, mid+1,r,x,y,fa,son);
	}
}
void swp(int x, int y, int k){
	if(x == y) return;
	int fax,fay,sonx,sony;
	find(1,1,n,(x)*(1<<k)+1,(x+1)*(1<<k),fax,sonx);
	find(1,1,n,(y)*(1<<k)+1,(y+1)*(1<<k),fay,sony);
//	cout << fax << " " << sonx << " " << fay << " " << sony << endl;
	sonx == 1 ? node[node[fax].rs].fa = fay : node[node[fax].ls].fa = fay;
	sony == 1 ? node[node[fay].rs].fa = fax : node[node[fay].ls].fa = fax;
	
	swap((sonx == 1 ? node[fax].rs : node[fax].ls) , (sony == 1 ? node[fay].rs : node[fay].ls));
	while(fax != fay){
		push_up(fax);
		push_up(fay);
		fax = node[fax].fa;
		fay = node[fay].fa;
	}
	push_up(fax);
}
int query(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		return node[pos].sum;
	}
	int mid = (l+r) >> 1;
	push_down(pos);
	int res = 0;
	if(x <= mid){
		res += query(node[pos].ls, l, mid, x,y); 
	}
	if(mid < y){
		res += query(node[pos].rs, mid+1, r, x, y);
	}
	push_up(pos);
	return res;
}
signed main(){
	freopen("seg15.in","r",stdin);
	freopen("seg15.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x,k;
			cin >> x >> k;
			modify(1,1,n,x,k);
		} 
		if(op == 2){
			int x, k;
			cin >> x >> k;
			reverse(1,1,n,x*(1<<k)+1,(x+1)*(1<<k));
		}
		if(op == 3){
			int x,y,k;
			cin >> x >> y >> k;
			swp(x,y,k);
		}
		if(op == 4){
			int l,r;
			cin >> l >> r;
			cout << query(1,1,n,l,r) << endl;
		}
	}
	return 0;
}
/*
8 10
1 2 3 4 5 6 7 8
4 3 5
2 1 1
4 3 3
4 4 5
3 1 2 1
4 6 8
3 0 1 0
4 2 3
1 1 8
4 1 2
*/

/*
4 9
1 4 3 2 
2 1 1
3 2 0 0
2 1 0
4 2 4
3 1 2 0
2 0 2
2 1 1
1 4 5
3 0 0 1

*/
/*
8 10
1 5 2 5 2 4 5 1 
3 7 2 0
4 5 8
3 0 5 0
4 5 8
3 1 2 1
4 5 8
3 0 0 1
4 5 8
3 0 4 0
4 5 8
*/

