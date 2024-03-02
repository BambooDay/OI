#include <bits/stdc++.h>
const int N = 4e6+10;
#define int unsigned long long

using namespace std;
int n,k,a[N],ans,U,seed;
int d(int x, int dig){
	return ((x>>dig)&1);
}
signed main(){
	freopen("bing.in","r",stdin);
	freopen("bing.out","w",stdout);
	cin >> n >> seed >> k;
	srand(seed);
	U = (k == 64 ? 0ull : (1ull << k)) - 1ull;
	mt19937_64 rnd(seed);
	for(int i = 1; i <= n; i++) a[i] = rnd() & U;
	for(int dig = 0; dig < 64; dig++){
		int _1 = 0,_0 = 0,res = 0;
		for(int i = 1;i <= n; i++){
			if(d(a[i],dig)) res += (i-1)*(i-2)/2,_1++;
			else res += _1*_0,_0++;
		}
		ans += (res<<dig);
	}		
	cout << ans;
	return 0;
}
