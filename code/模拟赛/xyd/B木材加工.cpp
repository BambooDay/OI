#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
struct wood{
	int l, w;
}a[6000];
bool cmp(wood x, wood y){
	if(x.l != y.l) return x.l > y.l;
	return x.w > y.w;
}
int dp[6000];
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		cin >> a[i].l >> a[i].w;
		dp[i] = 1;
	}
	sort(a+1,a+1+n,cmp);
//	for(int i =1 ; i <= n; i++){
//		cout << a[i].l << " " << a[i].w << endl;
//	}
	for(int i =2; i <= n; i++){
		for(int j =1; j < i; j++){
			if(a[j].l < a[i].l || a[j].w < a[i].w){
				dp[i] = max(dp[i],dp[j]+1);
//				cout << j << " " << i << endl;
			}
		}
	}
	int ans = -1;
	for(int i =1;i <= n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
