#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
const int N = 1e3+10;
const int M = 2e4+10;
const int INF = 0x3f3f3f3f;
const int mod =  998244353;
using namespace std;
int n, a[N],f[N][2*M];
int ans;
int p = 20000;
signed main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
//	for(int i = 1; i <= n; i++){
//		ans++;
//		for(int j = i-1; j ; j--){
//			f[i][a[i] - a[j] + p]+= f[j][a[i] - a[j] + p] + 1;
//			f[i][a[i] - a[j] + p] %= mod;
//			ans += f[j][a[i] - a[j] + p]+1;
//			ans %= mod;
//		}
//	}
	 p=20000;
	for(int i=1;i<=n;i++){
        ans++;
        for(int j=i-1;j;j--){
            f[i][a[i]-a[j]+p]+=f[j][a[i]-a[j]+p]+1;
            f[i][a[i]-a[j]+p]%=mod;
            ans+=f[j][a[i]-a[j]+p]+1;
            ans%=mod;
        }
    }
	cout<< ans;
	return 0;
}
