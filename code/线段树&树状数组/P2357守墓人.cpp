#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define ls(fa) fa * 2
#define rs(fa) fa * 2 + 1
const int N = 4e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int a[N];
int node[4*N];
int add[4*N];
void push_up(int cur){
	node[cur] = node[ls(cur)] + node[rs(cur)];
}
void build(int cur, int l, int r){
	if(l == r){
		node[cur] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(ls(cur),l,mid);
	build(rs(cur),mid+1,r);
	push_up(cur);
}
void ad(int cur, int l, int r, int k){
	node[cur] += (r - l + 1) * k;
	add[cur] += k;
}
void push_down(int cur,int l,int r){
	int mid = (l + r) >> 1;
	ad(ls(cur),l,mid,add[cur]);
	ad(rs(cur),mid+1,r,add[cur]);
	add[cur] = 0;
}
void update(int cur, int l, int r, int x, int y, int k){
	if(x <= l && r <= y){
		node[cur] += (r - l + 1) * k;
		add[cur] += k;
		return;
	}
	push_down(cur,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid){
		update(ls(cur),l,mid,x,y,k);
	}
	if(y > mid){
		update(rs(cur),mid+1,r,x,y,k);
	}
	push_up(cur);
}
int find(int cur, int l, int r,int x, int y){
	push_down(cur,l,r);
	if(x <= l && r <= y){
		return node[cur];
	}
	int mid = (l + r) >> 1;
	int res = 0;
	if(x <= mid){
		res += find(ls(cur),l,mid,x,y);
	}
	if (y > mid){
		res += find(rs(cur),mid+1,r,x,y);
	}
	return res;
}
signed main(){
	int t;
	cin >> n >> t;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	build(1,1,n);
	while(t--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y,k;
			cin >> x >> y >> k;
			update(1,1,n,x,y,k);
		}
		if(op == 2){
			int k;
			cin >> k;
			update(1,1,n,1,1,k);
		}
		if(op == 3){
			int k;
			cin >> k;
			update(1,1,n,1,1,-k);
		}
		if(op == 4){
			int x, y;
			cin >> x >> y;
			cout << find(1,1,n,x,y) << endl;
		}	
		if(op == 5){
			cout << find(1,1,n,1,1) << endl;
		}	
	}
	return 0;
}
