#include <bits/stdc++.h>
const int mod = 1e9+7;

using namespace std;
int n;
int dp[15] = {1};
string s = " helloworld";

int main(){
	char ch;
	while((ch = getchar()) != EOF){
		for(int i = 10; i >= 1; i--){
			if(ch == s[i] || ch+32 == s[i]) dp[i] = (dp[i-1]+dp[i]) % mod;
		}
	}		
	cout << dp[10] << endl;
	return 0;
} 
