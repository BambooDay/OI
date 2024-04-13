#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define ReFor(i,r,l) for(int i=(r);i>=(l);--i)
const int N=1000010;
const int mod=1000000007;
typedef long long ll;
using namespace std;
int n;
int S[N],T[N],S_pre_cnt[3],S_suf_cnt[3],T_pre_cnt[3],T_suf_cnt[3];
ll fac[N],invfac[N];
template<typename T1,typename T2>
void Add(T1 &a,T2 b){a+=b;if(a>=mod)a-=mod;return;}
template<typename T1,typename T2>
void Sub(T1 &a,T2 b){a-=b;if(a<0)a+=mod;return;}
ll qpow(ll a,int b)
{
    ll res=1;
    while(b)
    {
        if(b&1)(res*=a)%=mod;
        (a*=a)%=mod;b>>=1;
    }
    return res;
}
ll binom(int n,int m)
{
    if((n<0) || (m<0) || (n<m))return 0;
    ll res=fac[n];(res*=invfac[m])%=mod;(res*=invfac[n-m])%=mod;return res;
}
struct Binom
{
    int lim,A,S,S1;
    ll res;
    void clear(){res=0;lim=0;A=0;S=0;S1=0;return;}
    void brute_calc(){res=0;For(j,0,lim){ll delta=binom(A,j);(delta*=binom((S-A),(S1-j)))%=mod;Add(res,delta);}return;}
    void add_lim(){++lim;ll delta=binom(A,lim);(delta*=binom((S-A),(S1-lim)))%=mod;Add(res,delta);return;}
    void sub_lim(){ll delta=binom(A,lim);(delta*=binom((S-A),(S1-lim)))%=mod;Sub(res,delta);--lim;return;}
    void add_A(){ll delta=binom(A,lim);(delta*=binom((S-A-1),(S1-lim-1)))%=mod;Sub(res,delta);++A;return;}
}Part_1,Part_2;
void solve()
{
    cin>>n;For(i,1,n){char ch;cin>>ch;if(ch!='?')S[i]=(ch-'0');else S[i]=2;}For(i,1,n){char ch;cin>>ch;if(ch!='?')T[i]=(ch-'0');else T[i]=2;}
    For(i,1,n){if(!(i&1)){if(S[i]!=2)S[i]^=1;if(T[i]!=2)T[i]^=1;}}
    ll ans=0;For(i,0,2){S_pre_cnt[i]=0;T_pre_cnt[i]=0;S_suf_cnt[i]=0;T_suf_cnt[i]=0;}For(i,1,n){++S_suf_cnt[S[i]];++T_suf_cnt[T[i]];}
    Part_1.clear();Part_2.clear();
    Part_1.S=(S_suf_cnt[2]+T_suf_cnt[2]-1);Part_1.S1=(T_suf_cnt[2]-(S_suf_cnt[0]-T_suf_cnt[0])-1);
    Part_2.S=(S_suf_cnt[2]+T_suf_cnt[2]);Part_2.S1=(T_suf_cnt[2]-(S_suf_cnt[0]-T_suf_cnt[0]));
    For(i,1,n-1)
    {
        ++S_pre_cnt[S[i]];--S_suf_cnt[S[i]];++T_pre_cnt[T[i]];--T_suf_cnt[T[i]];
        int A=(S_pre_cnt[2]+T_pre_cnt[2]),A1=(T_pre_cnt[2]+(T_pre_cnt[0]-S_pre_cnt[0]));
        int B=(S_suf_cnt[2]+T_suf_cnt[2]),B1=(T_suf_cnt[2]-(S_suf_cnt[0]-T_suf_cnt[0]));
        if(i==1){Part_1.lim=(A1-1);Part_1.A=A;Part_1.brute_calc();Part_2.lim=(A1-1);Part_2.A=A;Part_2.brute_calc();}
        else
        {
            if(S[i]==0){Part_1.sub_lim();Part_2.sub_lim();}
            if(S[i]==2){Part_1.add_A();Part_2.add_A();}
            if(T[i]==0){Part_1.add_lim();Part_2.add_lim();}
            if(T[i]==2){Part_1.add_lim();Part_1.add_A();Part_2.add_lim();Part_2.add_A();}
        }
        {
            ll res1=B;if(res1<0)Add(res1,mod);(res1*=binom((A+B-1),(A1+B1-1)))%=mod;ll res2=B1;if(res2<0)Add(res2,mod);(res2*=binom((A+B),(A1+B1)))%=mod;
            ll res=res1;Sub(res,res2);Sub(ans,res);
        };
        {ll res=Part_1.res;(res*=B)%=mod;if(res<0)Add(res,mod);(res*=2)%=mod;Add(ans,res);};
        {ll res=Part_2.res;(res*=B1)%=mod;if(res<0)Add(res,mod);(res*=2)%=mod;Sub(ans,res);};
    }
    cout<<ans<<"\n";return;
}
int main()
{
    fac[0]=1;For(i,1,N-1){fac[i]=i;(fac[i]*=fac[i-1])%=mod;}
    invfac[N-1]=qpow(fac[N-1],(mod-2));ReFor(i,N-2,1){invfac[i]=(i+1);(invfac[i]*=invfac[i+1])%=mod;}invfac[0]=1;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)solve();return 0;
}