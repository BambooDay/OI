#include<bits/stdc++.h>
#define ll long long
const int N=2e5+5;
using namespace std;
int n,tot;
ll ans,u,v;
struct Node{
	int l,r,siz;
}tr[40*N];

int build(int  &pos,int l,int r,int val){
	pos = ++tot;
	tr[pos].siz++;
	if(l == r) return pos;
	int mid=(l+r)>>1;
	if(val <= mid) build(tr[pos].l,l,mid,val);
	else build(tr[pos].r,mid+1,r,val);
	return pos;
}

int merge(int x,int y,int l,int r) {
	if(!y||!x) return x+y;
	if(l == r) {
		tr[x].siz += tr[y].siz;
		return x;
	}
	u += 1ll*tr[tr[x].r].siz*tr[tr[y].l].siz;
	v += 1ll*tr[tr[x].l].siz*tr[tr[y].r].siz;
	int mid = (l+r)>>1;
	tr[x].l = merge(tr[x].l,tr[y].l,l,mid);
	tr[x].r = merge(tr[x].r,tr[y].r,mid+1,r);
	tr[x].siz = tr[tr[x].l].siz+tr[tr[x].r].siz;
	return x;
}

int dfs() {
	int pos,val;
	cin >> val;
	if(val == 0){ 
		int ls = dfs(),rs = dfs();
		u = 0;
		v = 0;
		pos = merge(ls,rs,1,n);
		ans += min(u,v);
	} else build(pos,1,n,val);
	return pos;
}

int main() {
	cin >> n;
	dfs();
	cout << ans;
	return 0;
}

