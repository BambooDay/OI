#include <bits/stdc++.h>
const int N = 2e5+10;
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
using namespace std;
int n,m;
int node[N <<2];
void modify(int pos, int l, int r, int x, int y){
	if(l == r){
		node[pos] = y;
		return;
	}
	int mid = l+r >> 1;
	if(x <= mid){
		modify(ls(pos),l,mid,x,y);
	}else{
		modify(rs(pos),mid+1,r,x,y);
	}
	node[pos] = min(node[ls(pos)],node[rs(pos)]);
}
int query(int pos,int l,int r, int x){
	if(r <= x){
		return node[pos];
	}
	int mid = (l+r) >> 1;
	int res = query(ls(pos),l,mid,x);
	if(mid < x){
		res = min(res,query(rs(pos),mid+1,r,x));
	}
	return res;
}
int a[N];
int pre[N];
struct ques{
	int l,r,id,ans;
}ask[N];
bool cmp1(ques x, ques y){
	if(x.r != y.r) return x.r < y.r;
	return x.l < y.l;
}
bool cmp2(ques x, ques y){
	return x.id < y.id;
}
int main(){
//	freopen("P4137_11.in","r",stdin);
	cin >> n >> m;
	for(int i =1;i <= n; i++){
		cin >> a[i];	
		a[i]++;
	}
	for(int i = 1; i <= m;i ++) {
		cin >> ask[i].l >> ask[i].r;
		ask[i].id = i;
	}
	sort(ask+1,ask+1+m,cmp1);
	int last = 0;
//	cout << query(1,1,n,N-8) << endl;
	for(int i = 1 ;i <= m; i++){
		for(int j = last+1; j <= ask[i].r; j++){
			modify(1,1,N-8,a[j],j);
		}
		last = ask[i].r;
		int l = 1,r = N-8;
		int ans;
		while(l <= r){
			int mid = (l+r) >> 1;
			if(query(1,1,N-8,mid) < ask[i].l){
				r = mid-1;
				ans = mid;
			}else{
				l = mid+1;
			}
//			cout << mid << " " << query(1,1,n,mid) << endl;
		}
		ask[i].ans = ans-1;
//		return 0;
	}
	sort(ask+1,ask+1+m,cmp2);
	for(int i = 1; i <= m; i++){
		cout << ask[i].ans << endl;
	}
	return 0;
}
