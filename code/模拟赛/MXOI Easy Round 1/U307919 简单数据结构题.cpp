#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
ll x, y;
ll add[N],a[N];

int main(){
	scanf("%d %d %lld %lld",&n,&m,&x,&y);
	add[1] = 1,add[2] = 1;
	for(int i =1;i <= n; i++) cin >> a[i];
	for(int i = 3;i <= n; i++){
		add[i] = (x*add[i-1]%mod+y*add[i-2]%mod)%mod;
	}
//	while(m--){
//		int l, r;
//		scanf("%d%d",&l,&r);
//		for(int i = 0;i+l<=r; i++){
//			a[i+l] = (a[i+l] + add[i+1]) % mod;
//		}
//	}
	for(int i = 1;i <= n; i++) cout << a[i] << " ";
	return 0;
}
