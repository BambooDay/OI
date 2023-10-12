#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
int n,m,cnt = 1;
string s,t,c;
stack<pair<int,int> > st;
void dfs(int step){
	if(step > n){
		//cout << s << endl;
		int cnt = 0;
		for(int i = 1;i < n; i++){
			if(s[i] != s[i+1]) cnt++;
		}
		if(cnt == m){
			for(int i = 1;i <= n; i++){
				cout << s[i];
			}
			exit(0);
		}
		return;
	}
	//int cnt = 0;
	//for(int i = 1;i < step-1; i++){
	//	if(s[i] != s[i+1]) cnt++;
	//}	
	//if(cnt > m+1) return;
	for(int i = step; i  <= n; i++){
		if(s[i] == '?'){
			s[i] = '0';
			dfs(i+1);
			s[i] = '1';
			dfs(i+1);
			s[i] = '?';
			break;
		}
		if(i == n) dfs(i+1);
	}
}
int main(){
	freopen("list.in","r",stdin);
	freopen("list.out","w",stdout);
	cin >> n >> m >> s;
	s = " " + s;
	bool f = 1;
	for(int i = 1;i <= n; i++){
		if(s[i] != '?'){
			f = 0;
			break;
		}
		//s[i] = '0';
	}
	if(f){
		if(m+1 > n){
			cout << -1;
			return 0;
		}
		for(int i  =1;i <= n; i++) s[i] = '0';
		s += "0";
		for(int i = n; i > n-m; i--){
			s[i] = (s[i+1] == '0' ? 1 : 0);
		}
		for(int i = 1;i <= n; i++) cout << s[i];
	}else {
		dfs(1);
		cout << -1;
	}
	return 0;
}
/*
5 3
0??1?
*/