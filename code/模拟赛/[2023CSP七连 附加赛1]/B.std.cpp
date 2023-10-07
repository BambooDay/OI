#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include "assert.h"
#include<algorithm>
#define ll long long
using namespace std;
#define I inline ll
#define her1 19260817
#define cht 998244353
#define IV void
#define ull unsigned long long
#define mem(x,val)memset(x,val,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register ll i=j;i<=n;i++)
#define DL(i,j,n)for(register ll i=j;i>=n;i--)
#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(ll i=j;i>=n;i--)
//#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#include<set>
mt19937_64 rnd(her1);
const int maxn = 2e5+5;
ll n,m,w[maxn],lst[maxn];
#define ls (o<<1)
#define rs (o<<1|1)
struct Matrix{
	ll mat[3][3];
	IV print(){
		F(i,0,2){
			F(j,0,2)cout<<mat[i][j]<<" ";
			puts("");
		}
	}
	ll*operator[](const ll&x){return mat[x];}
	IV clear(){F(i,0,2)F(j,0,2)mat[i][j]=-1e18;}
}xds[4*maxn],ep,pos[maxn];
IV cmax(ll&x,ll val){x<val?x=val,0:0;}
Matrix operator*(const Matrix&A,const Matrix&B){
	Matrix ans;ans.clear();
	F(k,0,2)F(i,0,2)F(j,0,2)cmax(ans[i][j],A.mat[i][k]+B.mat[k][j]);
	return ans;
}
IV build(ll o,ll l,ll r){
	if(l==r){
		xds[o].clear();
		xds[o].mat[0][0]=1-(w[l+1]-w[l]);
		xds[o].mat[2][0]=0;
		xds[o].mat[0][1]=-w[l+1];
		xds[o].mat[1][1]=0;
		xds[o].mat[2][2]=0;
		pos[l]=xds[o];
		return;
	}
	ll mid=l+r>>1;build(ls,l,mid);build(rs,mid+1,r);
	xds[o]=xds[rs]*xds[ls];
}
Matrix Q(ll o,ll l,ll r,ll x,ll y){
	if(x<=l&&r<=y)return xds[o];
	if(r<x||l>y)return ep;ll mid=l+r>>1;
	return Q(rs,mid+1,r,x,y)*Q(ls,l,mid,x,y);
}
int main(){
	 freopen("bbb04.in","r",stdin);
	 freopen("bbb04.out","w",stdout);
	n=read();F(i,1,n)w[i]=read();ep.clear();F(i,0,2)ep[i][i]=0;
	F(i,1,n)if(w[i]==w[i-1])lst[i]=lst[i-1];else lst[i]=i;
	build(1,0,n-1);m=read();
	while(m--){
		ll l=read(),r=lst[read()],ans=0,nd=0;
		if(l>=r){puts("0");continue;}Matrix tmp=Q(1,0,n-1,l-1,r-1);
		ans=max(tmp.mat[0][1],tmp.mat[2][1]);printf("%lld\n",ans+w[r]);
	}
	return 0;
}
