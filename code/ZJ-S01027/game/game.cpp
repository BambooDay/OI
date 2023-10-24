#include <bits/stdc++.h>

using namespace std;
int n;
string s;
long long ans = 0;
void check(int l, int r){
	stack<char> st;
	for(int i = l; i <= r; i++){
		if(st.empty()){
			st.push(s[i]);
			continue;
		}
		if(st.top() == s[i]){
			st.pop();
		}else{
			st.push(s[i]);
		}
	}
	if(st.empty()){
		ans++;
	} 
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> s;
	//dfs(0,"");
	s = " " + s;
	for(int len = 2; len <= n; len+=2){
		for(int i = 1;i <= n; i++){
			if(i+len-1 > n) break;
			check(i,i+len-1);
		}
	}
	cout <<ans;
	return 0;
}