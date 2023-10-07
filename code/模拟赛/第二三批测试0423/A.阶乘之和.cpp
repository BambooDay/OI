#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e6;
using namespace std;
ll qsm(int x){
	ll ans = 1;
	for(int i = 2; i <= x; i++){
		ans = ans * i % mod;
	}
	return ans;
} 
int n;
ll ans = 0;
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n; i++){
//		cout << qsm(i) << endl;
		ans = (ans + qsm(i)) % mod;
	}
	cout << ans;
	return 0;
}
