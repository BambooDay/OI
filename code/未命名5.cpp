#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const long long INF=214748364700000;
int n,m,sum=0,cnt=0;
int fa[100100],f[30][100100],dep[100100],v1[30][100100],v2[30][100100];
int head[200100],nxt[200100],to[200100],val[200100];
struct Edge
{
	int x,y,z,in;
}e[300100];
bool cmp(Edge a,Edge b) {return a.z<b.z;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void addedge(int x,int y,int z)
{
	cnt++;
	nxt[cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	val[cnt]=z;
}
void dfs(int u,int pre)
{
	for(int i=head[u];i!=-1;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		dep[v]=dep[u]+1,f[0][v]=u;
		v1[0][v]=val[i],v2[0][v]=-INF;
		dfs(v,u);
	}
}
int Lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[i][x]]>=dep[y]) x=f[i][x];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	return f[0][x];
}
int get(int u,int v,int k)
{
	int res=-INF; 
	for(int i=20;i>=0;i--)
		if(dep[f[i][u]]>=dep[v])
		{
			if(k!=v1[i][u]) res=max(res,v1[i][u]);
            else res=max(res,v2[i][u]);
            u=f[i][u];
		}
	return res;
}
signed main()
{
	memset(head,-1,sizeof(head));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(cnt==2*n-2) break;
		int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			sum+=e[i].z;
			e[i].in=1;
			addedge(e[i].x,e[i].y,e[i].z);
			addedge(e[i].y,e[i].x,e[i].z);
		}
	}
	dep[1]=1;dfs(1,0);
	for(int i=1;i<=21;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j]=f[i-1][f[i-1][j]];
			v1[i][j]=max(v1[i-1][j],v1[i-1][f[i-1][j]]);
			v2[i][j]=max(v2[i-1][j],v2[i-1][f[i-1][j]]);
			if(v1[i-1][j]>v1[i-1][f[i-1][j]]) v2[i][j]=max(v2[i][j],v1[i-1][f[i-1][j]]);
            else if(v1[i-1][j]<v1[i-1][f[i-1][j]]) v2[i][j]=max(v2[i][j],v1[i-1][j]);
		}
	int ans=INF;
	for(int i=1;i<=m;i++)
		if(!e[i].in)
		{
			int l=Lca(e[i].x,e[i].y);
			int res=max(get(e[i].x,l,e[i].z),get(e[i].y,l,e[i].z));
			ans=min(ans,e[i].z-res);
		}
	printf("%lld",ans+sum);
	return 0;
}
