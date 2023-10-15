#include<bits/stdc++.h>

#define ll long long
#define int long long

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

const int N=5e5+5;

int n,P1[N],P2[N],S1[N],S2[N],L1[N],L2[N],a[N],q;

// 1...i / i...1 / i...n / n...i / [1...i] => [i+1...n] / [i...n] => [1...i-1]

struct BIT{
	int c[N];
	void clear(){memset(c,0,sizeof(c));}
	int lowbit(int x){return x&(-x);}
	void add(int x,int k){for(int i=x;i<=n;i+=lowbit(i))c[i]+=k;}
	int sum(int x,int res=0){for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
}T,A,B;

signed main(void){
	freopen("C10.in","r",stdin);
	freopen("C10.out","w",stdout);

	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();

	T.clear();
	for(int i=1;i<=n;i++){
		Mod(P1[i]=P1[i-1]+T.sum(n)-T.sum(a[i])),T.add(a[i],1);
		Mod(P2[i]=(1ll*i*(i-1)/2)%mod+mod-P1[i]);
	}
	T.clear();
	for(int i=n;i>=1;i--){
		int cnt=n-i+1;
		Mod(S1[i]=S1[i+1]+T.sum(a[i])),T.add(a[i],1);
		Mod(S2[i]=(1ll*cnt*(cnt-1)/2)%mod+mod-S1[i]);
	}
	
	for(int i=1;i<=n;i++)B.add(i,1);
	int cur=0;
	for(int i=1;i<=n;i++){
		add(cur,mod-(A.sum(n)-A.sum(a[i]))),B.add(a[i],-1);
		add(cur,B.sum(a[i])),A.add(a[i],1);
		L1[i]=cur;
	}
	for(int i=1;i<=n;i++)Mod(L2[i]=1ll*(i-1)*(n-i+1)%mod-L1[i-1]);

	int st=1,rev=0,ans=0,pw=ksm(233,q-1),iv=inv(233);
	for(int i=1;i<=q;i++){
		char c=getchar();while(c!='0'&&c!='1')c=getchar();
		if(c=='0'){
			if(rev==0)st=st%n+1;
			else st=(st-2+n)%n+1;
		}
		if(c=='1'){
			if(rev==0)st=(st-2+n)%n+1;
			else st=st%n+1;
			rev^=1;
		}
		int res=0;
		if(rev==0){
			add(res,S1[st]),add(res,P1[st-1]),add(res,L2[st]);
			add(ans,1ll*res*pw%mod);
		}
		else{
			add(res,P2[st]),add(res,S2[st+1]),add(res,L1[st]);
			add(ans,1ll*res*pw%mod);
		}
		pw=1ll*pw*iv%mod;
	}

	cout<<(ans%mod+mod)%mod<<endl;

	return 0;
}
