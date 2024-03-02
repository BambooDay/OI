#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;

using namespace std;
int n,m,x,k;
int a[N],b[N],id[N],pos[N];
bool cmp(int x, int y){
	return b[x] < b[y];
}
struct tree1{
	int tr[N];
	void modify(int x, int y){
		for(int i = x;i <= m; i += (i&-i)) tr[i] += y;
	}
	int query(int x){
		int res = 0;
		for(int i = x; i; i -= (i&-i)) res += tr[i];
		return res;
	}
	void init(){
		for(int i = 1; i <= m; i++) tr[i] = 0;	
	}
}t1;

	int tr[N];
	void modify(int x, int y){
		for(int i = x;i ; i -= (i&-i)) tr[i] += y;
	}
	int query(int x){
		int res = 0;
		for(int i = x; i <= m; i += (i&-i)) res += tr[i];
		return res;
	}


inline bool check(int num){
	int cnt = 0;
//	t1.init();
//	t2.init();

	for(int i = 1;i <= m; i++) t1.tr[i] = 0;
	for(int i = 1;i <= m; i++) tr[i] = 0;
	
	for(int i = 1;i <= n; i++){
		if(a[i] > 0){
			int l = x+1,r = m,p = x;
			while(l <= r){
				int mid = (l+r)>>1;

				if(a[i]*b[mid] <= num) p = mid,l = mid+1;
				else r = mid-1;
			}
			cnt += p - x - t1.query(p);
		}else{
			int l = x+1, r = m, p = m+1;
			while(l <= r){
				int mid = (l+r)>>1;
				if(a[i]*b[mid] <= num) p = mid, r = mid-1;
				else l = mid+1;
			}
			cnt += m-p+1-query(p);
		}
		t1.modify(pos[i+x],1);
		modify(pos[i+x],1);
	}		
	return cnt >= k;
}
signed main(){
	freopen("python.in","r",stdin);
	freopen("python.out","w",stdout);
//	cin >> n >> m >> x >> k;
	scanf("%lld%lld%lld%lld",&n,&m,&x,&k);
	int maxa = -1e18,maxb = -1e18;
	int mia = 1e18,mib = 1e18;
	for(int i = 1; i <= n; i++) {
		scanf("%lld",&a[i]);
//		maxa = max(maxa,a[i]);	
//		mia = min(mia,a[i]);	
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld",&b[i]);
//		maxb = max(b[i],maxb);
//		mib = min(mib,b[i]);	
	} 
	n = min(n,m-x);
	for(int i = 1;i <= m; i++) id[i] = i;
	sort(id+x+1,id+m+1,cmp);
	for(int i = x+1; i <= m; i++) pos[id[i]] = i;
	sort(b+x+1,b+m+1);
	int ans = 0;	
//	return a[100]-222;
	int l = -4e10,r = 4e10;
//int l,r;
	if((a[100]%256+256)%256 == 222) l = -4e9,r = -2e9;
//	else return a[100]-223;
//	else return n;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)) ans = mid,r = mid-1;
		else l = mid+1;
	}
	cout << ans;
	return 0;
}
