#include <bits/stdc++.h>
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1| 1
const int N = 2e6;
const int INF = 0xfffffffffffffff;

using namespace std;
int n, q, ans[N],H[N],a[N],b[N];
vector<pair<int,int> > Q[N],E[N];
int c[N],d[N],tag[N];

void push_up(int pos){
	c[pos] = max(c[ls(pos)],c[rs(pos)]);
	d[pos] = max(d[ls(pos)],d[rs(pos)]);
}

void build(int pos, int l, int r){
	c[pos] = d[pos] = tag[pos] = -INF;
	if(l == r) return;
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
}
void calc(int p, int val) {
	tag[p] = max(tag[p], val);
	d[p] = max(d[p], c[p] + tag[p]);
}

void push_down(int pos){
	if(tag[pos] == -INF) return;
	tag[ls(pos)] = max(tag[(ls(pos))],tag[pos]);
	d[ls(pos)] = max(d[ls(pos)],c[ls(pos)] + tag[ls(pos)]);
	tag[rs(pos)] = max(tag[(rs(pos))],tag[pos]);
	d[rs(pos)] = max(d[rs(pos)],c[rs(pos)] + tag[rs(pos)]);
	tag[pos] = -INF;
}

void change(int pos , int l, int r, int x, int y){
	if(l == r){
		c[pos] = y;
		tag[pos] = -INF;
		return;
	}
	push_down(pos);
	int mid = (l+ r) >> 1;
	if(x <=mid){
		change(ls(pos),l,mid,x,y);
	}else{
		change(rs(pos),mid+1,r,x,y);
	}
	push_up(pos);
} 


void update(int pos, int l, int r, int x, int y, int z){
	if(x <= l && y >= r){
		tag[pos] = max(tag[pos],z);
		d[pos] = max(d[pos],c[pos] + tag[pos]);
		return;
	}
	push_down(pos);
	int mid = (l+r) >> 1;
	if(x <= mid){
		update(ls(pos),l,mid,x,y,z);
	}
	if(y > mid){
		update(rs(pos),mid+1,r,x,y,z);
	}
	push_up(pos);
}
int ask(int pos, int l, int r, int x, int y){
	if(x <= l && y >= r) return d[pos];
	push_down(pos);
	int mid = (l + r) >> 1;
	int ans = -INF; 
	if(x <= mid) ans = max(ans,ask(ls(pos),l,mid,x,y));
	if(y > mid) ans = max(ans,ask(rs(pos),mid+1,r,x,y));
	return ans;
}


void work(){
	build(1,1,n);
	for(int i = 1;i <= n; i++){
		for(auto p :E[i]) change(1,1,n,p.first,p.second?H[p.first] : -INF);
		if(i > a[i]) update(1,1,n,max(i-b[i],1ll),i-a[i],-H[i]);
		for(auto it: Q[i]) ans[it.first] = max(ans[it.first],ask(1,1,n,it.second,i));
	}
}


void solve(){
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> H[i] >> a[i] >> b[i];
	for(int i = 1; i <= n; i++){
		if(i+a[i] <= n){
			E[i + a[i]].push_back({i,1});
			if(i+b[i]+1 <= n) E[i+b[i]+1].push_back({i,0});
		}
	}
	cin >> q;
	for(int i = 1; i <= q; i++){
		int l,r;
		cin >> l >> r;
		Q[r].push_back({i,l});
		ans[i] = -1;
	}
	work();
	for(int i = 1; i <= n; i++){
		H[i] = 1e9-H[i];
	}
	work();
	for(int i = 1; i <= q; i++){
		cout << ans[i] << endl;
	}
}
signed main(){
	solve();
	return 0;
}

/*
5
10 2 4
1 1 1
2 1 3
1 1 1
100 1 1
5
1 2
2 3
1 3
1 4
1 5
*/
