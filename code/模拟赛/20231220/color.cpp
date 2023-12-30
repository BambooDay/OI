#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;

using namespace std;
int g[105];
int C[205][205];
int n,m,p,q;
int ksm(int a,int b) {
	int ans = 1;
	while(b) {
		if(b&1) ans = ans * a % mod;
		b>>=1;
		a = a*a%mod;
	}
	return ans;
}
struct jca {
	int a[105][105];
};
jca operator * (jca x,jca y) {
	jca res;
	for(int i = 1; i <= p; i++) {
		for(int j = 1; j <= p; j++) {
			res.a[i][j] = 0;
			for(int k = 1; k <= p; k++) {
				res.a[i][j] = (res.a[i][j] + x.a[i][k]*y.a[k][j]%mod)%mod;
			}
		}
	}
	return res;
}
jca x,y;
void init(){
	C[0][0] = 1;
	for(int i = 1; i <= 200; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
		}
	}
	for(int i = 1;i <= 100; i++){
		g[i] = ksm(i,n);
		for(int j =1;j < i; j++){
			g[i] = ((g[i]-g[j]*C[i][j]%mod)%mod+mod)%mod;
		}
	}
	for(int i = 1;i <= p; i++){
		for(int j = 1;j <= p; j++){
			if(i+j < q){
				x.a[i][j] = 0;
			}else{
				if(i < q && j < q){
					for(int k = max(q,i)-j; k <= i && k+j <= p; k++){
						x.a[i][j] = (x.a[i][j] + C[j][i-k]*C[p-j][k]%mod*g[i]%mod)%mod;
					}
				}else{
					x.a[i][j] = C[p][i] * g[i] % mod;
				}
			}
		}
	}
	for(int i = 1; i <= p; i++) y.a[i][1] = g[i]*C[p][i]%mod;
}
jca mksm(jca a,int b) {
	jca ans;
	ans = a;
	b--;
	while(b) {
		if(b&1) ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

signed main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> n >> m >> p >> q;
	init();
	jca ans = mksm(x,m-1);
	ans = ans*y;
	int res = 0;
	for(int i = 1; i <= p; i++){
		res = (res + ans.a[i][1]) %mod;
	}
	cout << res;
	return 0;
}

