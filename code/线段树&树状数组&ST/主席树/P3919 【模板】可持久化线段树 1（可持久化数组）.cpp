#include <bits/stdc++.h>
const int N = 1e6+10;
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
		sum(now) = y;
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
const int up = 1e6+10;
const int down = 1;
int ask(int pos, int l, int r, int x){
	if(l == r) return sum(pos);
	int mid = (l+r) >> 1;
	if(x <= mid) return ask(ls(pos),l,mid,x);
	else return ask(rs(pos),mid+1,r,x);
}
void build(int pos, int l, int r){
	if(l == r){
		sum(pos) = a[l];
		return;
	} 
	int mid = (l+r) >> 1;
	ls(pos) = ++tot;
	rs(pos) = ++tot;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos); 
}
int main(){
	cin >> n >> m;
	root[0] = ++tot;
	for(int i = 1; i <= n; i++){
//		cin >> a[i];
		scanf("%d",&a[i]);
	}
	build(root[0],1,n);
	for(int i = 1;i <= m; i++){
		int v,op,x,y;
//		cin >> v >> op;
		scanf("%d%d",&v,&op);
		if(op == 1){
//			cin >> x >> y;
			scanf("%d%d",&x,&y); 
			root[i] = ++tot;
			update(root[v],root[i],1,n,x,y);
		}else{
//			cin >> x;
			scanf("%d",&x);
			root[i] = root[v];
			printf("%d\n",ask(root[i],1,n,x));
		}
	}
	return 0;
}
