#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int  long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int node[N*4],a[N],add[N*4],mult[N*4];

int n, m, p;
bool used[N*4];
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
//ll max(ll x, ll y){
//	return x > y ? x:y;
//}
void push_up(int cur){
	node[cur] = max(node[ls(cur)] , node[rs(cur)]);
}
void mul(int cur,int ad,int mu,bool flag){
	if(flag){
		mult[cur] = mu;
		add[cur] = ad;
		node[cur] = mu + ad;
		used[cur] =1;
	}else{
		add[cur] += ad;
		node[cur] += ad;
	}
}
void push_down(int cur){
	mul(ls(cur),add[cur],mult[cur],used[cur]);
	mul(rs(cur),add[cur],mult[cur],used[cur]);
//	if(used[cur]){
//		mult[ls(cur)] = mult[cur];
//		mult[rs(cur)] = mult[cur];
//		add[ls(cur)] = add[cur];
//		add[rs(cur)] = add[cur];
//		node[ls(cur)] = mult[cur] + add[cur];
//		node[rs(cur)] = mult[cur] + add[cur];
//	}else{
//		add[ls(cur)] += add[cur];
//		add[rs(cur)] += add[cur];
//		node[ls(cur)] += add[cur];
//		node[rs(cur)] += add[cur];
//	}
	add[cur] = 0;
	mult[cur] = 0;
	used[cur] = 0;
}

void build(int cur,int l,int r){
    node[cur] = -1e18;
    if(l==r){
		node[cur]=a[l];
		return ;
	}
    int mid=(l+r)>>1;
    build(ls(cur),l,mid);
    build(rs(cur),mid+1,r);
    push_up(cur);
} 
void up_date_change(int cur, int l, int r, int x, int y, int k){
	if(x <= l && r <= y){
		mult[cur] = k;
		add[cur] = 0;
		node[cur] = k;
		used[cur] = 1;
		return;
	}
	push_down(cur);
	int mid = (l + r) >> 1;
	if(x <= mid){
		up_date_change(ls(cur),l,mid,x,y,k);
	}
	if(y > mid){
		up_date_change(rs(cur),mid+1,r,x,y,k);
	}
	push_up(cur);
}
void up_date_add(int cur, int l, int r, int x, int y, int k){
	if(x <= l && r <= y){
		add[cur] += k;
		node[cur] += k;
		return;
	}
	push_down(cur);
	int mid = (l + r) >> 1;
	if(x <= mid){
		up_date_add(ls(cur),l,mid,x,y,k);
	}
	if(y > mid){
		up_date_add(rs(cur),mid+1,r,x,y,k);
	}
	push_up(cur);
}

int find(int x,int y,int l,int r,int cur){
	if(x<=l&&r<=y)return node[cur];
	push_down(cur);
	int mid=(l+r)>>1;
	int res=-1e18;
	if(x<=mid)res=max(res,find(x,y,l,mid,ls(cur)));
	if(y>mid) res=max(res,find(x,y,mid+1,r,rs(cur)));
	return res ;
}
signed main(){
	scanf("%lld%lld",&n,&m);
//	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
//		cin >> a[i];
	}
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, k;
			scanf("%lld%lld%lld",&x,&y,&k);
//			cin >> x >> y >> k;
			up_date_change(1,1,n,x,y,k);
		}else if(op == 2){
			int x, y, k;
			scanf("%lld%lld%lld",&x,&y,&k);
//			cin >> x >> y >> k;
			up_date_add(1,1,n,x,y,k);
		}else{
			int x, y;
			scanf("%lld%lld",&x,&y);
//			cin >> x >> y;
			printf("%lld\n",find(x,y,1,n,1));
//			cout << find(x,y,1,n,1) << endl; 
		}
	}
	return 0;
}
