#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
int n,k;
struct Node{
	int a,b,c;
}tr[N];
int ans;
int dp[N]; 
bool cmp(Node x, Node y){
	return 1ll*x.c*y.b < 1ll*y.c*x.b;
}
void solve(){
	cin >> k >> n;
	ans = 0;
	memset(dp,0,sizeof dp);
	for(int i =1;i <= n; i++) cin >> tr[i].a;
	for(int i =1;i <= n; i++) cin >> tr[i].b;
	for(int i =1;i <= n; i++) cin >> tr[i].c;
	sort(tr+1,tr+1+n,cmp);
	for(int i =1;i <= n; i++){
		for(int j = k; j>=tr[i].c; j--){
			dp[j] = max(dp[j],tr[i].a-tr[i].b*(j)+dp[j-tr[i].c]);
		}
	}	
	for(int i = 1; i <= k; i++) ans = max(ans,dp[i]);
	cout << ans << endl;
}
signed main(){
	solve();
	return 0;
}
