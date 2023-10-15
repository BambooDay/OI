#include<bits/stdc++.h>

#define ll long long

using namespace std;

inline int read(){
    int x=0,f=1;char c=getchar();
    for(;(c<'0'||c>'9');c=getchar()){if(c=='-')f=-1;}
    for(;(c>='0'&&c<='9');c=getchar())x=x*10+(c&15);
    return x*f;
}

const int mod=998244353;
int ksm(int x,int y,int p=mod){
    int ans=1;
    for(int i=y;i;i>>=1,x=1ll*x*x%p)if(i&1)ans=1ll*ans*x%p;
    return ans%p;
}
int inv(int x,int p=mod){return ksm(x,p-2,p)%p;}
mt19937 rnd(time(0));
int randint(int l,int r){return rnd()%(r-l+1)+l;}
void add(int &x,int v){x+=v;if(x>=mod)x-=mod;}
void Mod(int &x){if(x>=mod)x-=mod;}

void cmax(int &x,int v){x=max(x,v);}
void cmin(int &x,int v){x=min(x,v);}

const int N=7505;
const int M=55;

bitset<N>f[M][M];
int n,m;
int sum[N][M],vis[N][M];

signed main(void){
	freopen("D10.in","r",stdin);
	freopen("D10.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++){
        int k=read();
        while(k--){
            int p=read();
            vis[i][p]=sum[i][p]=1;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)sum[i][j]+=sum[i][j-1];
    // for(int l=1;l<=m;l++)for(int r=l;r<=m;r++)for(int i=1;i<=n;i++)f[l][r][i]=(sum[i][r]!=sum[i][l-1]);
    int ans=0;
    // for(int l=1;l<=m;l++)for(int r=l;r<=m;r++){
    //     cout<<"f "<<l<<" "<<r<<" = ";for(int i=1;i<=n;i++)cout<<f[l][r][i];puts("");
    // }
    for(int i=1;i<=n;i++){
        bitset<N>res;int lst=0;
        for(int j=1;j<=m;j++)if(vis[i][j])res^=f[lst+1][j],lst=j;
        for(int l=1;l<=m;l++)for(int r=l;r<=m;r++)f[l][r][i]=(sum[i][r]!=sum[i][l-1]);
        // cout<<"i = "<<i<<" res = ";for(int j=1;j<=n;j++)cout<<res[j];puts("");
        ans+=res.count();
    }
    cout<<ans<<endl;

    return 0;
}
