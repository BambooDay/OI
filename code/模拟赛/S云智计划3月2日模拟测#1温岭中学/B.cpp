#include <bits/stdc++.h>
const int N = 1005;

using namespace std;
string a,b;
int dp[2][N];

int main(){
	freopen("vlcs.in","r",stdin);
	freopen("vlcs.out","w",stdout);
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	for(int i = 1; i < a.size(); i++){
		for(int j = 1; j < b.size(); j++){
			dp[i&1][j] = max(dp[(i-1)&1][j],dp[i&1][j-1]);
			if(a[i] == b[j]) dp[i&1][j] = max(dp[i&1][j],dp[(i-1)&1][j-1]+1);
		}
		for(int j = 1; j < b.size(); j++){
			dp[(i+1)&1][j] = 0;
		}
		
	}	
	cout << dp[(a.size()-1)&1][b.size()-1];
	return 0;
}
