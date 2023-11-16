#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
//struct Node{
//	int l,r,sum;
//}tr[N*40];
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline int read(){
    register int x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
int ll[N*40],rr[N*40],sumsum[N*40];

int rt[N];
int tot = 0;
void push_up(int pos){
	sumsum[pos] = sumsum[ll[pos]] + sumsum[rr[pos]];
}
void build(int last, int &now, int l, int r,int x){
	now = ++tot;
	ll[now] = ll[last];
	rr[now] = rr[last];
	sumsum[now] = sumsum[last];
	if(l == r){
		sumsum[now]++;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid){
		build(ll[last],ll[now],l,mid,x);
	}else{
		build(rr[last],rr[now],mid+1,r,x);
	}
	push_up(now);
} 
int kth(int L, int R, int l, int r,int k){
	if(l == r){
		return l;
	}
	int mid = (l+r)>>1;
	if(sumsum[ll[R]] - sumsum[ll[L]] < k) return kth(rr[L],rr[R],mid+1,r,k-(sumsum[ll[R]] - sumsum[ll[L]]));
	else return kth(ll[L],ll[R],l,mid,k);
}
int query(int L, int R, int l, int r,int x){
	if(l == r){
		return sumsum[R] - sumsum[L];
	}
	int mid = (l+r)>>1;
	if(x <= mid) return query(ll[L],ll[R],l,mid,x);
	else return query(rr[L],rr[R],mid+1,r,x);
}
int a[N];
int n,m;

//void ins(int l,int r,int p,int &x,int pre){
//	sumsum[x=++tot]=sumsum[pre];
//	if(l==r)return sumsum[x]++,void();
//	int m=l+r>>1;
//	if(p<=m)ins(l,m,p,ll[x],ll[pre]),rr[x]=rr[pre];
//	else ins(m+1,r,p,rr[x],rr[pre]),ll[x]=ll[pre];
//	push_up(x);
//}
//int kth(int x,int y,int l,int r,int k){
//	if(l==r)return l;
//	int m=l+r>>1,sz=sumsum[ll[y]]-sumsum[ll[x]];
//	if(sz<k)return kth(rr[x],rr[y],m+1,r,k-sz);
//	return kth(ll[x],ll[y],l,m,k);
//}
//int query(int x,int y,int l,int r,int p){
//	if(l==r)return sumsum[y]-sumsum[x];
//	int m=l+r>>1;
//	if(p<=m)return query(ll[x],ll[y],l,m,p);
//	return query(rr[x],rr[y],m+1,r,p);
//}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	n = read();
	m = read();
	for(int i = 1;i <= n; i++){
//		cin >> a[i];
//		scanf("%d",&a[i]);
		build(rt[i-1],rt[i],1,n,read());
//		ins(1,n,read(),rt[i],rt[i-1]);
	}
	while(m--){
		int l = read(),r = read(),k = read();
//		cin >> l >> r >> k;
		int rk = 1,ans = -1,nd = (r-l+1)/k+1;
		while(rk <= r-l+1){
			int q = kth(rt[l-1],rt[r],1,n,rk);
			if(query(rt[l-1],rt[r],1,n,q) >= nd){
				ans = q;
				break;
			}
			rk += nd;
		} 
//		cout << ans << '\n';	
		printf("%d\n",ans);			
	}
	return 0;
}
