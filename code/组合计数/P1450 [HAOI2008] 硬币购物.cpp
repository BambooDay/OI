#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int c[5],d[5],n,s;
ll dp[N];
int main(){
	cin >> c[0] >> c[1] >> c[2] >> c[3] >> n;
	dp[0] = 1;
	for(int i = 0; i < 4;i++){
		for(int j = c[i]; j <= 100000; j++){
			dp[j] += dp[j-c[i]];
		}
	}
	while(n--){
		cin >> d[0] >> d[1] >> d[2] >> d[3];
		cin >> s;
		ll ans = 0;
		for(int i = 0; i < (1 << 4);i++){
			int m = s;
			for(int j = 0; j < 4; j++){
				if(i>>j & 1){
					m -= c[j] * (d[j]+1);
				}
			}
			if(m >= 0){
				ans += dp[m] * (__builtin_popcount(i)&1?-1:1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
