#include <bits/stdc++.h>
const int N = 5e5+10;
const int M = 3e6+10;

using namespace std;
int tr[M][30];
int n;
int tot = 0;
int dp[M];
int ans = 0;
int tag[M];
void add(string s){
//	cout << s << " " << id << endl;
	int p = 0;
	for(int i = s.size()-1; i>=0; i--){
		int ch = s[i] - 'a'+1;
		if(!tr[p][ch]) tr[p][ch] = ++tot;
		p = tr[p][ch]; 
	}
	tag[p]++;
}
void dfs(int pos){
//	if(tag[pos]) dp[pos] = tag[pos];
	int d1 = 0,d2 = 0,son = 0;
	for(int i = 1; i <= 26; i++){
		if(!tr[pos][i]) continue;
		int to = tr[pos][i];
		dfs(to);
		son += tag[to];
		if(!tag[to]) continue;
		if(dp[to] > d1) d2 = d1,d1 = dp[to];
		else if(dp[to] > d2) d2 = dp[to];
	} 
	ans = max(ans,tag[pos]+d1+d2+max(son-2,0));
	dp[pos] = tag[pos] + max(0,son-1)+d1;
} 
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		string s;
		cin >> s;
		add(s);
	}
	dfs(0);
	cout << ans;
	return 0;
}

