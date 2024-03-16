#include <bits/stdc++.h>
const int N = 1e5+10;
const int M = 3e5+10;
#define ull unsigned long long
const ull BASE = 13331;

using namespace std;
int n;
ull hs[M],base[M];
string s;
ull ssh;
vector<pair<int,string> > e[N];
int ans = 0;
ull get(int l, int r){
	return hs[r]-hs[l-1]*base[r-l+1];
}
void dfs(int pos,int last, int now){
//	cout << pos << endl;
	for(int i = last; i+s.size()-1 <= now; i++){
//		cout << get(i,i+s.size()-1) << " " << ssh << endl;
		if(get(i,i+s.size()-1) == ssh) ans++;
	}
	for(auto to : e[pos]){
//		cout << to.first << endl;
		int nw = now;
		for(int i = 0; i < to.second.size(); i++){
			nw++;
			hs[nw] = hs[nw-1]*BASE+to.second[i];
		}
		dfs(to.first,now-s.size()+2,nw);
	}
} 
int main(){
	cin >> n;
	for(int i = 2;i <= n; i++){
		int fa;
		string t;
		cin >> fa >> t;
		e[fa].push_back({i,t});
//		cin >> e[i].first >> e[i].second;
	}
	cin >> s;
	base[0] = 1;
	for(int i = 1; i <= 3e5; i++) base[i] = base[i-1]*BASE;
	for(int i = 0; i < s.size(); i++) ssh = ssh*BASE+s[i];
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
