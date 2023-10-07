#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
ll a[N*2],cnt = 0;
struct pay{
	ll ma,mi;
}p[N];
int cf[N*2];
map<ll,ll> m;
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		cin >> p[i].mi >> p[i].ma;
		a[++cnt] = p[i].mi;
		a[++cnt] = p[i].ma;
	} 
	sort(a+1,a+1+cnt);
	cnt = unique(a+1,a+1+cnt) - a - 1;
	for(int i =1;i <= cnt; i++){
		m[a[i]+cnt+1] = i;
		m[i] = a[i]+cnt+1;
//		cout << m[i] << " ";
	}
	for(int i =1;i <= n; i++){
		cf[m[p[i].mi+cnt+1]]++;
		cf[m[p[i].ma+cnt+1]+1]--;
	}
	ll ans = -1;
	int sum = 0;
	for(int i = 1; i <= cnt; i++){
		sum += cf[i];
//		cout << cf[i] << " ";
		ans = max(ans,sum * (m[i]-cnt-1));
	}
	cout << ans;
	return 0;
}
