#include <bits/stdc++.h>
const int  N =1e5+10;

using namespace std;
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

int n;
int dfn[N],L[N],R[N],idx;
vector<int> e[N];
void dfs(int pos){
	dfn[pos] = L[pos] = R[pos] = ++ idx;
	for(int to : e[pos]){
		dfs(to);
		R[pos] = max(R[pos],R[to]);
	}
}
int tr1[N],tr2[N];
void modify(int tr[],int x, int y){
	for(int i = x; i <= n; i += (i&-i)){
		tr[i] += y;
	}
}
int query(int tr[], int x){
	int ans = 0;
	for(int i = x; i; i -= (i&-i)){
		ans += tr[i];
	}
	return ans;
}
int lastans = 0;
void solve(){
	int l,r;
	scan(l);
	scan(r);
	//cin >> l >> r;
	l ^= lastans,r ^= lastans;
	l %= n,r %= n;
	l++,r++;
	if(r < l) swap(l,r);
	int ans = 0;
	for(int i = l; i <= r; i++){
		modify(tr1,dfn[i],1);
		ans += query(tr1,R[i]) - query(tr1,L[i]-1);
		ans += query(tr2,dfn[i]);
		modify(tr2,R[i]+1,-1);
		modify(tr2,L[i],1);
	}
	putint(ans,'\n');
	//cout << ans << endl;
	lastans = ans;
	for(int i = l; i <= r; i++){
		modify(tr1,dfn[i],-1);
		modify(tr2,R[i]+1,1);
		modify(tr2,L[i],-1);
	}
}
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	scan(n);
	//cin >> n;
	for(int i = 1;i < n; i++){
		int p;
		//cin >> p;
		scan(p);
		e[p].push_back(i+1);
	}
	dfs(1);
	int q;
	//cin >> q;
	scan(q);
	while(q--) solve();
	flush();
	return 0;
}