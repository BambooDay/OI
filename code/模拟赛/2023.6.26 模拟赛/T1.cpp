#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ll
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, a[N],b[N];
vector<int> pos[N];
signed main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	cin >> n;
	ll sum = 0,ans = 1e18;
	int m = 0;
	for(int i =1;i <= n; i++){
		cin >> a[++m];
		if(m > 1){
			sum += abs(a[m]-a[m-1]);
			if(a[m] == a[m-1]) m--;
			else{
				pos[a[m]].push_back(m);
			}
		}else{
			pos[a[m]].push_back(m);
		}
		b[m] = a[m];
	}
	sort(b+1,b+1+m);
	int cnt = unique(b+1,b+1+m) - b-1;
//	for(int i = 1; i <= cnt; i++){
//		for(int j : pos[b[i]]){
//			cout << j << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1; i <= cnt; i++){
		int sum1 = 0;
		int cnt1=0,c[N];
		for(int j : pos[b[i]]){
			if(j != 1){
				c[++cnt1] = a[j-1];
				sum1 += abs(a[j] - a[j-1]);
			}
			if(j != m){
				c[++cnt1] = a[j+1];
				sum1 += abs(a[j] - a[j+1]);
			}
//			cout << sum1 << endl;
		}
		sort(c+1,c+1+cnt1);
		int v = c[cnt1 / 2 + cnt1% 2];
//		cout << v << endl;
		for(int j = 1; j <= cnt1; j++){
			sum1 -= abs(v - c[j]);
		}
//		cout << sum1 << endl;
		ans = min(ans,sum - sum1);
	}
	cout << ans;
	return 0;
}
/*
5
9 4 3 8 8
*/
