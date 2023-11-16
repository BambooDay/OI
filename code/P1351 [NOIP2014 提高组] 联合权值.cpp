#include <bits/stdc++.h>
const int mod = 10007;
const int N = 2e5+10;
using namespace std;
vector<int> e[N];
int w[N];
int n;
int sum;
long long ans = -1;
int main(){
	cin >> n;
	for(int i =1;i < n; i++){
		int u,v ;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	for(int i =1;i <= n; i++) cin >> w[i];
	for(int i = 1;i <= n; i++){
		int ma1 = -1,ma2 = -1;
		int sum1 = 0,sum2 = 0;
		for(int to : e[i]){
			sum1 = (sum1+w[to])%mod;
			sum2 = (sum2+w[to]*w[to]%mod)%mod;
			if(w[to] > ma1)ma2 = ma1, ma1 = w[to];
			else ma2 = max(ma2,w[to]);
		}
//		cout << ma1 << " " << ma2 << endl;
		sum = ((sum+sum1*sum1%mod-sum2)%mod + mod)%mod;
		ans = max(ans,ma1*ma2*1ll);
	} 
	cout << ans << " " << sum;
	return 0;
}
