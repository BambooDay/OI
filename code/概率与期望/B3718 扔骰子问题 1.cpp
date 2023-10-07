#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;

using namespace std;
ll ksm(ll a, int b){
	int ans = 1;
	while(b){
		if(b  & 1){
			ans  = ans * a % mod;
		}
		a = a*a % mod;
		b >>= 1;
//		cout << ans << " ";
	}
	return ans; 
}
int n, m;
ll inv[N],inv6[N],mul5[N],mul[N];
void init(){
	mul[0] = mul5[0] = 1;
	for(int i = 1; i <= N-10; i++){
		mul[i] = mul[i-1] * i % mod;
		mul5[i] = mul5[i-1] * 5 % mod;
	}
	inv[N-10] = ksm(mul[N-10],mod-2);
//	cout << ksm(6,N-10) << " ";
	inv6[N-10] = ksm(ksm(6,N-10),mod-2);
	for(int i = N-11; i >= 0; i--){
		inv[i] = inv[i+1] * (i+1) % mod;
		inv6[i] = inv6[i+1] * 6 % mod;
	}
}
int t;
int main(){
//	cout << "\4935478" << endl;
	cin >> t;
	puts("tou");
	init();
	ll ans  = 0;
	while(t--){
		scanf("%d%d",&n,&m);
//		cin >> n >> m;
		ans ^= mul5[n-m]*mul[n]% mod*inv6[n]% mod*inv[m] % mod * inv[n-m] % mod;
//		cout << endl;
	}
//	cout << ans;
	printf("%lld",ans);
	return 0;
}
