#include <bits/stdc++.h>
const int N = 2e5+10;
#define int long long
const int mod = 998244853;
using namespace std;
int n;
int a[N],b[N];
int cnt[N];
int sum = 0;
stack<int> st; 
signed main(){
	cin >> n;
//	return n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1;i <= n; i++) cin >> b[i];
	sort(a+1,a+1+n);
	a[n+1] = 1e18;
	for(int i = 2;i <= n+1; i++){
		if(a[i] == a[i-1]) st.push(i);
		else{
			for(int j = a[i-1]+1; j < a[i]&&!st.empty(); j++){
				int x = st.top();
				st.pop();
				cnt[x] = (j - a[x])%mod;
			}
		}
	}
	sort(cnt+1,cnt+1+n,greater<int>());
	sort(b+1,b+1+n);
	for(int i = 1;i <= n; i++) sum = (sum+cnt[i]*b[i]%mod)%mod;
	cout << sum;
	return a[1];
}
