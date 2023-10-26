#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int  long long
const int N = 5e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int node[N*4],a[N],add[N*4],mult[N*4];

int n, m, p;

int ls(int fa){return fa * 2;}
int rs(int fa){return fa * 2 + 1;}

void push_up(int cur){
	node[cur] = (node[ls(cur)] + node[rs(cur)])% p;
}
void mul(int cur,int l, int r,int ad,int mu){
	node[cur]  = ((node[cur] * mu)% p + (r - l + 1) * ad) % p;
	mult[cur] = mu * mult[cur] % p;
	add[cur] = (add[cur] * mu + ad) % p;
}
void push_down(int cur,int l, int r){
	int mid = (l + r) >> 1;
	mul(ls(cur),l,mid,add[cur],mult[cur]);
	mul(rs(cur),mid+1,r,add[cur],mult[cur]);
	add[cur] = 0;
	mult[cur] = 1;
}

void up_date_add(int cur, int l, int r, int x, int y, int k){
	if(x <= l && r <= y){
		mul(cur,l,r,k,1);
		return;
	}
	push_down(cur,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid){
		up_date_add(ls(cur),l,mid,x,y,k);
	}
	if(y > mid){
		up_date_add(rs(cur),mid+1,r,x,y,k);
	}
	push_up(cur);
}
void up_date_mul(int cur, int l, int r, int x, int y, int k){
	if(x <= l && r <= y){
		mul(cur,l,r,0,k);
		return;
	}
	push_down(cur,l,r);
	int mid = (l + r) >> 1;
	if(x <= mid){
		up_date_mul(ls(cur),l,mid,x,y,k);
	}
	if(y > mid){
		up_date_mul(rs(cur),mid+1,r,x,y,k);
	}
	push_up(cur);
}
void modify(int cur,int l, int r, int x, int y){
	if(l == r){
		node[l] += y;//找到x
		return; 
	}
	int mid = (l + r) >> 1;
	if(x <= mid){//x在左儿子这里 
		modify(ls(cur),l,mid,x,y);
	} else{ //在右儿子这里 
		modify(rs(cur),mid+1,r,x,y); 
	}
	push_up(cur);
}
int find(int x,int y,int l,int r,int cur){
	int res=0;
	if(x<=l&&r<=y)return node[cur] % p;
	int mid=(l+r)>>1;
	push_down(cur,l,r);
	if(x<=mid)res+=find(x,y,l,mid,ls(cur));
	if(y>mid) res+=find(x,y,mid+1,r,rs(cur));
	return res % p;
}
void build(int cur,int l,int r){
    add[cur]=0;
    mult[cur] = 1;
    if(l==r){
		node[cur]=a[l]% p;
		return ;
	}
    int mid=(l+r)>>1;
    build(ls(cur),l,mid);
    build(rs(cur),mid+1,r);
    push_up(cur);
} 
signed main(){
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, k;
			cin >> x >> y >> k;
			up_date_mul(1,1,n,x,y,k);
		}else if(op == 2){
			int x, y, k;
			cin >> x >> y >> k;
			up_date_add(1,1,n,x,y,k);
		}else{
			int x, y;
			cin >> x >> y;
			cout << find(x,y,1,n,1) << endl; 
		}
	}
	return 0;
}
