#include<bits/stdc++.h>
const int N = 5e5+10;
#define ll long long
using namespace std;
char bg;
namespace Sub{
	int n,a[N];
	int x[N],y[N];
	int tx = 0,ty = 0;
	int rt[N],tot;
	struct Node{
		int l,r;
		int sum;
	}tr[N*85];
	#define ls(pos) tr[pos].l
	#define rs(pos) tr[pos].r
	#define sum(pos) tr[pos].sum
	void build(int &now, int last, int l, int r, int x){
		if(!now) now = ++tot;
		if(l == r){
			sum(now) = 1;
			return;
		}
		ls(now) = ls(last);
		rs(now) = rs(last);
		sum(now) = sum(last);
		int mid = (l+r)>>1;
		if(x <= mid)ls(now) = ++tot, build(ls(now),ls(last),l,mid,x);
		else rs(now) = ++tot,build(rs(now),rs(last),mid+1,r,x);
		sum(now) = sum(ls(now)) + sum(rs(now)); 
	}
	ll query(int pos, int l, int r, int x, int y){
		if(x <= l && r <= y) return sum(pos);
		int mid = (l+r)>>1;
		ll ans = 0;
		if(x <= mid) ans += query(ls(pos),l,mid,x,y);
		if(mid < y) ans += query(rs(pos),mid+1,r,x,y);
		return ans; 
	}
	ll ans = 0;
	void solve(){
		tx = 0,ty = 0,ans = 0;
		scanf("%d",&n);
		for(int i =1;i <= n; i++){
			scanf("%d",&a[i]);
			ans += query(rt[i-1],1,n,a[i],n); 
//			cout << 111;
			build(rt[i],rt[i-1],1,n,a[i]);
		} 
//		cout << ans << endl;
		for(int i = n; i; i--){
			while(tx && a[x[tx]] < a[i]) tx--;
			x[++tx] = i;
		}	
		for(int i = 1; i <= n; i++){
			while(ty && a[y[ty]] > a[i]) ty--;
			y[++ty] = i;
		} 
//		for(int i =1;i <= ty; i++){
//			cout << a[y[i]] << " ";
//		}
//		cout << endl;
//		cout << query(rt[6],1,n,1,7)  << endl;
		ll ma = 0;
		for(int i = 1; i <= tx; i++){
			for(int j = 1; j <= ty; j++){
				if(a[x[i]] < a[y[j]]) break;
				if(x[i] >= y[j]) continue;
				ll tmp = query(rt[y[j]-1],1,n,1,a[x[i]]-1) - query(rt[x[i]],1,n,1,a[x[i]]-1) - (query(rt[y[j]-1],1,n,1,a[y[j]]) - query(rt[x[i]],1,n,1,a[y[j]]));
//				cout << x[i] << " " << y[j] << " " << query(rt[y[j]-1],1,n,1,a[x[i]]-1) << " " <<  query(rt[x[i]],1,n,1,a[x[i]]-1) << " "<<  query(rt[y[j]-1],1,n,1,a[y[j]]) << " " <<  query(rt[x[i]],1,n,1,a[y[j]]) << endl;
				ma = max(ma,tmp);
			}
		}
		ans -= ma*2+1;
		cout << max(ans,0ll) << endl;
//		cout << tot<< endl;
		for(int i = 0; i <= tot; i++) tr[i].l = tr[i].r = tr[i].sum = 0;
		for(int i =0 ; i<= n; i++) rt[i] = 0;
		tot = 0;
	} 
	
}
char ed;
int main(){
//	cout << (&bg - &ed) / 1048576.0 << "\n"; 
	freopen("essenceoftwilight.in","r",stdin);
	freopen("essenceoftwilight.out","w",stdout); 
	int t,o;
	cin >> t >> o;
	while(t--) Sub::solve();
	return 0;
}

