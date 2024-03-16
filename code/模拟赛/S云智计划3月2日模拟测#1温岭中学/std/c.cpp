#include<iostream>
using namespace std;
const int MOD=998244353;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int f[105][1000005],s[105];
int n,k;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&k);
	int n=100,q; scanf("%d",&q);
		f[0][0]=1,s[0]=0;
		for(int x=1;x<=n;++x){
			s[x]=s[x-1]+x*k;
			for(int j=0;j<=s[x];++j){
				f[x][j]=f[x-1][j];
				if(j>=x){
					mo(f[x][j]+=f[x][j-x]);
					if(j>=(k+1)*x)
						mo(f[x][j]+=MOD-f[x-1][j-(k+1)*x]);
				}
//				printf("[%d %d %d]",x,j,f[x][j]);
			}
		}
	while(q--){
		int n,x; scanf("%d%d",&n,&x);
		int ans=0;
		for(int j=0;j<=min(s[x-1],s[n-x]);++j)
			ans=(ans+1ll*f[x-1][j]*f[n-x][j]%MOD*(k+1))%MOD;
		mo(ans+=MOD-1);
		printf("%d\n",ans);
	}
	return 0;
}
