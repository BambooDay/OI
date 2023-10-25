#include <bits/stdc++.h>
const int N = 2e5+10;
const int M = 1e6+10;
#define ls(fa) tr[fa].l
#define rs(fa) tr[fa].r
#define sum(fa) tr[fa].sum

using namespace std;
struct Node{
	int l=0,r=0;
	int sum = 0;
}tr[M*30];
int tot = 1;
int root[N],a[N],n,m;
void push_up(int pos){
	sum(pos) = sum(ls(pos))+sum(rs(pos)); 
}
void update(int last, int now,int l, int r,int x, int y){
	if(l == r){
		sum(now) = sum(last)+y;
		return;
	}
	ls(now) = ls(last);
	rs(now) = rs(last);
	int mid = (l+r) >> 1;
	if(x <= mid){
		ls(now) = ++tot;
		update(ls(last),ls(now),l,mid,x,y);
	}else{
		rs(now) = ++tot;
		update(rs(last),rs(now),mid+1,r,x,y);
	}
	push_up(now);
}
const int up = 1e9+5;
const int down = -(1e9+5);
int kth(int last, int now, int l, int r, int k){
	if(l == r) return l;
	int mid = (l+r) >> 1;
	int val = sum(ls(now)) - sum(ls(last));
	if(val >= k) return kth(ls(last),ls(now),l,mid,k);
	else return kth(rs(last),rs(now),mid+1,r,k-val);
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1;i <= n; i++){
		root[i] = ++tot;
		update(root[i-1],root[i],down,up,a[i],1);
	}
	while(m--){
		int l,r,k;
		cin >> l >> r >> k;
		cout << kth(root[l-1],root[r],down,up,k) << endl;
	}
	return 0;
}
