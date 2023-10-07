#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, a[N],b[N];
int dp[N];
map<int,int> m;

int main(){
	cin >> n;
	for(int i = 1;i <= n; i++) {
		cin >> a[i];
		m[a[i]] = i;
		dp[i] = INF;
	}
	for(int i = 1;i <= n; i++) cin >> b[i];
	int len = 0;
//	dp[1] = m[b[1]];
	for(int i = 1;i <= n; i++){
		if(m[b[i]] > dp[len]) dp[++len] = m[b[i]];
		else{
			dp[upper_bound(dp+1,dp+len+1,m[b[i]]) - dp] = m[b[i]]; 
		}
	}
	cout << len ;
	
	return 0;
}
