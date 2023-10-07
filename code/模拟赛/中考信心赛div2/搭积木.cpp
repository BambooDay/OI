#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
ll sum[N];
ll a[N];
ll qmi[N],hmi[N];
int ans = 0;
int main(){
//	freopen("6.in","r",stdin);
	cin >> n;
	qmi[0] = 1e18;
	sum[0] = 0;
	for(int i =1;i <= n; i++){
		cin >> a[i];
		sum [i] = sum[i-1] + a[i];//前缀和 
	}
	for(int i = 1;i <= n; i++){
		qmi[i] = min(sum[i],qmi[i-1]);//从前往后找最小值 
	}
	hmi[n+1] = 1e18;
	for(int i = n; i > 0; i--){
		hmi[i] = min(hmi[i+1],sum[i]);
	}
	for(int i =1;i <= n; i++){
		if((hmi[i] - sum[i-1]) >= 0 && (qmi[i-1]+sum[n] - sum[i-1]) >= 0){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
