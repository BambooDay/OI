#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n,a[N];
int b[N];
int pre[N];
int node[N<<2];
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
void push_up(int pos){
	node[pos] =  min(node[ls(pos)],node[rs(pos)]);
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = b[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
int ask(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y) return node[pos];
	int mid = (l+r) >> 1;
	int res = 1e9;
	if(mid >= x){
		res = min(res,ask(ls(pos),l,mid,x,y));
	}
	if(mid < y){
		res = min(res,ask(rs(pos),mid+1,r,x,y));
	}
	return res;
	
}
int main(){
//	freopen("bbb04.in","r",stdin);
//	freopen("bbb04.ans","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = i;
		if(a[i] == a[i-1]) pre[i] = pre[i-1];
		b[i] = a[i];
	}	
	for(int i = n-1; i; i--){
		if(a[i] == a[i+1])b[i] = b[i+1]-1;
	}
//	for(int i = 1; i <= n; i++) cout << b[i] << " ";
//	cout << endl; 
	build(1,1,n);
	 int q;
	 cin >> q;
	 while(q--){
	 	int l,r;
	 	cin >> l >> r;
	 	r = pre[r];	
		if(l >= r){
			cout << 0 << endl;
			continue;
		}
//		cout << ask(1,1,n,l,r-1) << ' ';
		cout << a[r] - ask(1,1,n,l,r-1) << endl;
	 }
	return 0;
}
