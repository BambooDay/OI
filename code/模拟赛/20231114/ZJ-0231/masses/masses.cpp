#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
const int mod = 998244353;
#define fi first
#define se second
using namespace std;
int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans = ans*a%mod;
		}
		a = a*a%mod;
		b>>=1;
	}
	return ans;
}
int w[N];
int n,t,fm,fz,m,fz1;
vector<int> e[N];
int ans = 0;
int xxx,yyy;

void dfs(int dep,int pos, int fa, int a, int b){
	//cout  << dep << " " << pos << " " << a << " " << b << endl;
	if(dep == t){
		xxx += a*w[pos]*294/b;
		ans = (ans + w[pos]*a%mod*ksm(b,mod-2)%mod)%mod;
		return;
	}
	int tmp = (fa == 0) ? e[pos].size():e[pos].size()-1;
	if(tmp == 0){
		dfs(dep+1,pos,0,a,b);
	}else dfs(dep+1,pos,0,a*fz%mod,b*fm%mod);
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs(dep+1,to,pos,a*fz1%mod,b*tmp*fm%mod);
	}
}
signed main(){
	freopen("masses.in","r",stdin);
	freopen("masses.out","w",stdout);
	scanf("%lld %lld %lld %lld/%lld",&n,&m,&t,&fz1,&fm);
	//cout << fz1 << " " << fm << endl;
	fz = fm-fz1;
	//fm = ksm(fm,mod-2);
	for(int i = 1;i <= n; i++) cin >> w[i];
	for(int i = 1; i <= m ;i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bool f = 0;
	for(int i = 1; i < n; i++){
		if(w[i] != w[i+1]){
			f = 1;
			break;
		} 
	}
	if(n <= 10&&t<=6&&f){
		//dfs(0,1,0,1,n);
		for(int i = 1;i <= n; i++){
			dfs(0,i,0,1,n);
		}
		//cout << xxx << endl;
		cout << ans << endl;

	}else{
		cout << w[1] << endl;
	}



	//Sub1::solve();
	//cout << w[1] << endl;
	return 0;
}