#include <bits/stdc++.h>
const int N = 1e3+10;

using namespace std;
int n,k;
struct Node{
	int a,b;
}tr[N];
int ans;
int dp[N]; 
bool cmp(Node x, Node y){
	return x.b > y.b;
}
void solve(){
	ans = -1;
	memset(dp,0,sizeof dp);
	for(int i =1;i <= n; i++) cin >> tr[i].a;
	for(int i =1;i <= n; i++) cin >> tr[i].b;
	sort(tr+1,tr+1+n,cmp);
	for(int i =1;i <= n; i++){
		for(int j = k; j; j--){
			dp[j] = max(dp[j],max(0,tr[i].a-tr[i].b*(j-1))+dp[j-1]);
		}
	}	
	for(int i = 1; i <= k; i++) ans = max(ans,dp[i]);
	cout << ans << endl;
}
int main(){
	while(cin >>n >> k && n && k){
		solve();
	}
	return 0;
}
