#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 100003;
using namespace std;
ll n,m;
ll ksm(ll a, ll b){
	ll ans = 1, x = a % mod;
	while(b){
		if(b & 1){
			ans = ans * x % mod;
		}
		x = x * x % mod;
		b >>= 1;
	}
	return (ans+mod) % mod;
}

int main(){
	cin >> m >> n;
	cout << ((ksm(m,n) - m%mod*ksm(m-1,n-1)% mod)+mod)%mod;
	return 0;
}
