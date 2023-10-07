#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define ls(fa) (fa << 1)
#define rs(fa) ((fa << 1) + 1)
const int N = 5e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int cur[N<<4];
void push_up(int pos){
	cur[pos] = cur[ls(pos)] + cur[rs(pos)];
}
void build(int pos,int l, int r){
	if(l == r){
		cur[pos] = 0;
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void modify(int pos,int l, int r, int x, int y){
	if(l == r){
		cur[pos] += y;
		return;
	}
//	cout << pos << " "; 
	int mid = (l + r) >> 1;
	if(x <= mid){
		modify(ls(pos),l,mid,x,y);
	}else{
		modify(rs(pos),mid+1,r,x,y);
	}
	push_up(pos);
}
int query(int pos, int l, int r,int x, int y){
	if(x<= l && r <= y){
		return cur[pos];
	}
	int ans = 0;
	int mid = (l + r) >> 1;
	if(x <= mid && y >= l) ans += query(ls(pos),l,mid,x,y);
	if(x <= r && y > mid) ans += query(rs(pos),mid+1,r,x,y);
	return ans;
}
int n, w;

signed main(){
	cin >> n >> w;
//	build(1,1,n);
	while(w--){
		int a, b;
		char op;
		cin >> op >> a >> b;
//		cout << op;
		if(op =='x'){
			modify(1,1,n,a,b);
		}
		if(op == 'y'){
			cout << query(1,1,n,a,b) << endl;
		}
	}
	return 0;
}
