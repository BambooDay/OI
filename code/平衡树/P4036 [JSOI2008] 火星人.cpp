#include <bits/stdc++.h>
#define N 100010
using namespace std;
typedef unsigned int ull;
const ull base = 97 ;
int root,cnt;
char s[N];
ull B[1000010];
struct Node {
	int ls,rs,size,key;
	ull sum,val;
} a[N<<1];
struct par {
	int x,y;
};
inline void pushup(int x) {
	int ls=a[x].ls,rs=a[x].rs;
	a[x].sum=a[x].val;
	a[x].size=1;
	if(ls) a[x].sum-=a[x].val,a[x].sum+=a[ls].sum+a[x].val*B[a[ls].size],a[x].size+=a[ls].size;
	if(rs) a[x].sum+=a[rs].sum*B[a[ls].size+1],a[x].size+=a[rs].size;
}
int merge(int x,int y) {
	if(!x||!y) return x|y;
	if(a[x].key>a[y].key) {
		a[x].rs=merge(a[x].rs,y);
		pushup(x);
		return x;
	} else {
		a[y].ls=merge(x,a[y].ls);
		pushup(y);
		return y;
	}
}
par split(int x,int k) {
	if(!k) return (par){0,x};
	int ls=a[x].ls,rs=a[x].rs;
	if(k==a[ls].size) {
		a[x].ls=0;
		pushup(x);
		return (par) {
			ls,x
		};
	} else if(k==a[ls].size+1) {
		a[x].rs=0;
		pushup(x);
		return (par) {x,rs};
	} else if(k<a[ls].size) {
		par t=split(ls,k);
		a[x].ls=t.y;
		pushup(x);
		return (par) {t.x,x};
	} else {
		par t=split(rs,k-a[ls].size-1);
		a[x].rs=t.x;
		pushup(x);
		return (par) {x,t.y};
	}
}
inline int newnode(ull val) {
	int x=++cnt;
	a[x].ls=a[x].rs=0;
	a[x].size=1;
	a[x].sum=a[x].val=val;
	a[x].key=rand()*rand();
	return x;
}
void insert(int x,ull val) {
	par t=split(root,x);
	root=merge(t.x,merge(newnode(val),t.y));
}
ull query(int x,int k) {
	par t1=split(root,x-1),t2=split(t1.y,k);
	ull re=a[t2.x].sum;
	root=merge(t1.x,merge(t2.x,t2.y));
	return re;
}
void update(int x,ull y) {
	par t1=split(root,x-1),t2=split(t1.y,1);
	root=merge(t1.x,merge(newnode(y),t2.y));
}
void output(int x) {
	int ls=a[x].ls,rs=a[x].rs;
	if(ls) output(ls);
	printf("%lld ",a[x].val);
	if(rs) output(rs);
}
int build(int l,int r) {
	if(l==r) return newnode(s[l]-'a'+1);
	int mid=(l+r)>>1;
	return merge(build(l,mid),build(mid+1,r));
}
int main() {
	srand(20021214);
	B[0]=1;
	for(int i=1; i<=1000000; i++) B[i]=B[i-1]*base;
	scanf("%s",s+1);
	int n=strlen(s+1);
	root=build(1,n);
	int m;
	cin >> m;
	while(m--) {
		char opt;
		cin >> opt;
//		while(opt!='Q'&&opt!='R'&&opt!='I')opt=nc(/);
		int x;
		cin >> x;
		if(opt=='Q') {
			int y;
			cin >> y;
			int r=min(n-x+1,n-y+1)+1,l=0;
			while(l<r) {
				int mid=(l+r)>>1;
				if(query(x,mid)==query(y,mid)) l=mid+1;
				else r=mid;
			}
			printf("%d\n",l-1);
		} else if(opt=='R') {
			char d;
			cin >> d;
//			while(d<'a'&&d>'z')d=nc();
			ull val=d-'a'+1;
			update(x,val);
		} else {
			n++;
			char d;
			cin >> d;
//			while(d<'a'&&d>'z')d=nc();
			ull val=d-'a'+1;
			insert(x,val);
		}
	}
	return 0;
}

