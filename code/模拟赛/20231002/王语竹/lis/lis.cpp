#include<cstdio>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

using std::min;
static inline
int __my_rand (int *seed) {
    *seed = *seed * 1103515245 + 12345;
    return ((unsigned)*seed) / 34;
}
int gen (int N, int Lim, int seed, int* F) {
    int cur = 0;
    for (int i = 1; i <= N; i ++) {
        int rd = __my_rand(&seed);
        if (rd % std::min(10, cur + 1) == 0 && cur < Lim) F[i] = ++cur;
        else F[i] = (__my_rand(&seed) % cur) + 1;
    }
    return 0;
}

int n,lim,seed,f[10005];
int a[10005];
void dfs(int step){
	if(step > n){
		int dp[105] = {0};
		dp[1] = 1;
		for(int i = 2; i <= n; i++){
			dp[i] = 1;
			for(int j = i-1; j ; j--){
				if(a[i] > a[j]){
					dp[i] = max(dp[i],dp[j]+1);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(dp[i] != f[i]) return;
		}
		long long ans = 0,base = 1;
		for(int i = 1; i <= n; i++){
//			cout  << a[i] << " "<< dp[i] << " " << f[i] << endl;; 
			base = base * i % 998244353;
			ans = (ans + a[i]*base%998244353) % 998244353;
		}
		cout << endl; 
		cout << ans;
		exit(0);
	}
	for(int i = n; i >= 0 ; i--){
		a[step] = i;
		dfs(step+1);
	}
}
int main() {
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d%d%d",&n,&lim,&seed);
	gen(n,lim,seed,f);
	dfs(1);
	return 0;
}
