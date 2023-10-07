#include <bits/stdc++.h>

using namespace std;
int n,m,ans,dp[(1<<10)][(1<<10)][3],a[105];
vector<pair<int,int> > s;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char ch;
			cin >> ch;
			a[i] <<= 1;
			a[i] += (ch == 'H') ? 1 : 0; 
		}
	}	
	for(int i = 0; i < (1 << m); i++){
		if(((i << 1) & i) ||((i << 2) & i)) continue;
		int cnt = 0;
		int j = i;
		while(j){
			if(j & 1) cnt++;
			j >>= 1;
		}
		s.push_back(make_pair(i,cnt));
	}
	for(pair<int,int> S : s){
		if(S.first&a[1]) continue;
		dp[0][S.first][1] = S.second;
	}
	for(pair<int,int> P : s){
		for(pair<int,int> S : s){
			if(!(P.first&S.first) && !(P.first&a[1]) && !(S.first & a[2])){
				dp[P.first][S.first][2] = S.second + P.second; 
			}
		}
	}
	for(int i = 3; i <= n; i++){
		for(pair<int,int> L : s){
			if((L.first&a[i-1])) continue;
			for(pair<int,int> S : s){
				if(S.first&a[i] || L.first&S.first) continue;
				for(pair<int,int> FL : s){
					if(FL.first&L.first || FL.first&S.first) continue;
					dp[L.first][S.first][i%3] = max(dp[L.first][S.first][i%3],dp[FL.first][L.first][(i-1)%3]+S.second);
				}
			}
		}
	}
	for(auto L : s){
		for(auto S : s){
			ans = max(ans,dp[L.first][S.first][n%3]);
		}
	}
	cout<< ans;
	return 0;
}
