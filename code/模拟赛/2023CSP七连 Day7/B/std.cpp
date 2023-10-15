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

const int N=1e6+5;
int n,stk[N],C[2],top=0;

signed main(void){
	freopen("B10.in","r",stdin);
	freopen("B10.out","w",stdout);
	n=read();int ans=0;
	for(int i=1;i<=n;i++){
		char c=getchar();while(c!='0'&&c!='1')c=getchar();
		int x=c-'0';
		if(C[x^1]==0)stk[++top]=x,C[x]++,ans++;
		else{
			while(stk[top]!=(x^1))C[stk[top]]--,top--;
			C[stk[top]]--,stk[top]^=1,C[stk[top]]++;
		}
	}
	cout<<ans<<endl;

	return 0;
}
