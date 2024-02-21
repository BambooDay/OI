#include <bits/stdc++.h>
#define int long long
const int N = 3005;
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
using namespace std;
int dp[N][N];
int n,m,seed,limx;
int x[N],k[N],c[N];
int a[N];
int node[N][N<<2],add[N][N<<2];
void push_up(int id,int pos){
	node[id][pos] = node[id][ls(pos)] + node[id][rs(pos)];
}
void push_down(int id,int pos, int l, int r){
	int mid = (l+r) >> 1;
	node[id][ls(pos)] += add[id][pos] * (mid - l + 1);
	node[id][rs(pos)] += add[id][pos] * (r-mid);
	add[id][ls(pos)] += add[id][pos];
	add[id][rs(pos)] += add[id][pos];
	add[id][pos] = 0;
}
//void build(int id,int pos, int l, int r){
//	if(l == r){
//		node[id][pos] = a[l];
//		add[id][pos] = 0;
//		return;
//	}
//	int mid = (l+r) >> 1;
//	build(id,ls(pos),l,mid);
//	build(id,rs(pos),mid+1,r);
//	push_up(id,pos);
//}
void update(int id,int pos, int l, int r, int x, int y, int z){
	if(l >= x && r <= y){
		node[id][pos] += (r-l+1)*z;
		add[id][pos] += z;
		return;
	}
	push_down(id,pos,l,r);
	int mid = (l+r) >> 1;
	if(mid >= x){
		update(id,ls(pos),l,mid,x,y,z);
	}
	if(y > mid){
		update(id,rs(pos),mid+1,r,x,y,z);
	}
	push_up(id,pos);
}
int query(int id,int pos, int l, int r, int x, int y){
	if(x <= l && r <= y) return node[id][pos];
	push_down(id,pos,l,r);
	int mid = (l+r) >> 1;
	int ans = 0;
	if(mid >= x){
		ans += query(id,ls(pos),l,mid,x,y);
	}
	if(mid < y){
		ans += query(id,rs(pos),mid+1,r,x,y);
	}
//	push_up(pos);
	return ans;
}
int id;
uint64_t PRG_state;
uint64_t get_number(){
    PRG_state ^= PRG_state << 13;
    PRG_state ^= PRG_state >> 7;
    PRG_state ^= PRG_state << 17;
    return PRG_state;
}
int readW(int l,int r){
	return get_number()%(r-l+1)+l;
}

signed main(){
	cin >> n >> m >> id >> seed >> limx;
	PRG_state = seed;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		x[i] = readW(limx, n);
		k[i] = readW(1, x[i]);
		c[i] = readW(0, 1e7);
	}
	for(int i = 1; i <= n; i++){
		
	}
	return 0;
}
