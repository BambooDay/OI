#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1 << 12+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e8;

using namespace std;
int n, m;
bool v[20][N];
vector<int> s[20];
int mp[20];
ll dp[20][N];
int main(){
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		int num = 0;
		for(int j = 1; j <= n; j++){
			int x;
			 cin >> x;
			 num = (num << 1) + x;
		}
		mp[i] = num;
	}
	for(int i =0; i < (1 << n); i++){
		for(int j =1;j <= m; j++){
			int num = i & mp[j];
			if(!v[j][num] && !(num &(num << 1 | num >> 1))){
				v[j][num] =1 ;
				s[j].push_back(num);
			}
		}
	}
	s[0].push_back(0);
	s[m+1].push_back(0);
	dp[0][0] = 1;
	for(int i =1; i <= m+1; i++){
		for(int s1 : s[i]){
			for(int s2 : s[i-1]){
				if(!(s1 & s2)){
					dp[i][s1] += dp[i-1][s2];
					dp[i][s1] %= mod;
				}
			}
		}
	}
	cout << dp[m+1][0]%mod;
	return 0;
}
