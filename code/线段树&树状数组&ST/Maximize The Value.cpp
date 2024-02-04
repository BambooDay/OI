#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

struct node {
	long long sum,val;
	long long maxpre,maxsuf;
	friend node operator + (node x,node y) {
		node z;
		z.sum = x.sum + y.sum;
		z.maxpre = max(x.maxpre,x.sum+y.maxpre);
		z.maxsuf = max(y.maxsuf,y.sum+x.maxsuf);
		z.val = max(max(x.val,y.val),x.maxsuf+y.maxpre);
		return z;
	}
} seg[N<<2];
void pushup(int id) {
	seg[id] = seg[id<<1] + seg[id<<1|1];
}
void build(int l,int r,int id) {
	if(l == r) {
		seg[id].sum = 0;
		seg[id].maxpre = 0;
		seg[id].maxsuf = 0;
		seg[id].val = 0;
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	pushup(id);
}
void update(int l,int r,int id,int pos,int val) {
	if(l == r) {
		seg[id].sum += val;
		seg[id].maxpre += val;
		seg[id].maxsuf += val;
		seg[id].val += val;
		return;
	}
	int mid = (l+r)>>1;
	if(mid >= pos) update(l,mid,id<<1,pos,val);
	else update(mid+1,r,id<<1|1,pos,val);
	pushup(id);
}
node query(int l,int r,int id,int head,int tail) {
	if(l == head && r == tail) return seg[id];
	int mid = (l+r)>>1;
	if(mid >= tail) return query(l,mid,id<<1,head,tail);
	if(mid<head) return query(mid+1,r,id<<1|1,head,tail);
	return query(l,mid,id<<1,head,mid)+query(mid+1,r,id<<1|1,mid+1,tail);
}
vector<pair<int,int> >op[N];
struct qry {
	int l,r,id;
};
vector<qry> qy[N];
long long ans[N];
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= m; i++) {
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		op[l].push_back({x,i});
		op[r+1].push_back({-x,i});
	}
	int q;
	scanf("%d",&q);
	for(int i = 1; i <= q; i++) {
		int k,s,t;
		scanf("%d %d %d",&k,&s,&t);
		qy[k].push_back({s,t,i});
	}
	build(1,m,1);
	for(int i = 1; i <= n; i++) {
		for(auto j: op[i]){
			int val = j.first,id = j.second;
			update(1,m,1,id,val);
		}
		for(auto j: qy[i]){
			int l = j.l,r = j.r ,id = j.id;
			ans[id] = query(1,m,1,l,r).val;
		}
	}
	for(int i = 1; i <= q; i++) printf("%lld\n",ans[i]);
	return 0;
}

