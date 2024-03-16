#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e6+5,M=1e3+5;
int n,m,dp[M][M],ne[N][30],now[30];
char s[N],t[N];

signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=0;i<26;++i)
		now[i]=n+1;
	for(int i=n;i>=0;--i)
	{
		for(int j=0;j<26;++j)
			ne[i][j]=now[j];
		now[s[i]-'a']=i;
	}
	for(int i=0;i<=m;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=n+1;
	dp[0][0]=0;
	for(int i=0;i<m;++i)
		for(int j=0;j<=i;++j)
			if(dp[i][j]!=n+1)
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
				dp[i+1][j+1]=min(dp[i+1][j+1],ne[dp[i][j]][t[i+1]-'a']);
			}
	int ans=0;
	for(int i=1;i<=m;++i)
		if(dp[m][i]!=n+1)
			ans=i;
	write(ans);
	return 0;
}
