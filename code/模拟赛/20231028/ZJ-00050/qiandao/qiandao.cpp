#include <bits/stdc++.h>
const int N = 2e6+10;

using namespace std;
int n,ans;
int a[N],l[N],r[N];
int st[N],top;
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

int main(){
	freopen("qiandao.in","r",stdin);
	freopen("qiandao.out","w",stdout);
	//cin >> n;
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		a[i]++;
		while( top && a[st[top]] >= a[i] )top --;
		l[i] = st[top];
		st[++ top] = i;
	} 
	top = 0;
	st[0] = n + 1;
	for(int i = n;i >= 1;i --){
		while( top && a[st[top]] > a[i] )top --;
		r[i] = st[top];
		st[++ top] = i;
	}
	for(int i = 1;i <= n;i ++){
		int L = l[i],R = r[i];
		int mn = min(i - L, R - i);
		int ret = 1ll * mn * ( 2 * (i - L) - mn - 1 ) / 2;
		ans += ret;
	}
	putint(ans - n,'\n'); 
	flush();
	return 0;
}

