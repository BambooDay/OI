#include <bits/stdc++.h>
const int N = 5e5+10;
const int up = 5e4+10;
using namespace std;
struct Node{
	int l,r,sum;
}tr[N*40];
#define ls(pos) tr[pos].l
#define rs(pos) tr[pos].r
#define sum(pos) tr[pos].sum
int rt[N];
int tot = 0;
void push_up(int pos){
	sum(pos) = sum(ls(pos)) + sum(rs(pos));
}
void build(int last, int &now, int l, int r,int x){
	now = ++tot;
	ls(now) = ls(last);
	rs(now) = rs(last);
	sum(now) = sum(last);
	if(l == r){
		sum(now)++;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid){
		build(ls(last),ls(now),l,mid,x);
	}else{
		build(rs(last),rs(now),mid+1,r,x);
	}
	push_up(now);
} 
int kth(int L, int R, int l, int r,int k){
	if(l == r){
		return l;
	}
	int mid = (l+r)>>1;
	if(sum(ls(R)) - sum(ls(L)) < k) return kth(rs(L),rs(R),mid+1,r,k-(sum(ls(R)) - sum(ls(L))));
	else return kth(ls(L),ls(R),l,mid,k);
}
int query(int L, int R, int l, int r,int x){
	if(l == r){
		return sum(R) - sum(L);
	}
	int mid = (l+r)>>1;
	if(x <= mid) return query(ls(L),ls(R),l,mid,x);
	else return query(rs(L),rs(R),mid+1,r,x);
}
int a[N];
int n,m;

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		build(rt[i-1],rt[i],1,up,a[i]);
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		if((r-l+1)&1) {
			int tmp = kth(rt[l-1],rt[r],1,up,(r-l+2)/2);
			if(query(rt[l-1],rt[r],1,up,tmp)>(r-l+1)/2)
				printf("%d\n",tmp);
			else puts("0");
		} else {
			int tmp = kth(rt[l-1],rt[r],1,up,(r-l+1)/2),
				tnp = kth(rt[l-1],rt[r],1,up,(r-l+3)/2);
			if(tmp==tnp && query(rt[l-1],rt[r],1,up,tmp) > (r-l+1)/2) 
				printf("%d\n",tmp);
			else printf("0\n");
		}		
	}
	return 0;
}
