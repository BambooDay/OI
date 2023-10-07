#include <bits/stdc++.h>
const int N = 3e6+10;
using namespace std;
int tree[N][66],tot;
int cnt[N];
int get(char x){
	if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}
void add(string s){
	int p = 0;
	for(int i = 0; i < s.size(); i++){
		s[i] = get(s[i]);
		if(!tree[p][s[i]]) tree[p][s[i]] = ++tot;
		p = tree[p][s[i]];
		cnt[p]++;
	}
}
int ask(string s){
	int p = 0;
	for(int i = 0; i < s.size(); i++){
		s[i] = get(s[i]);
		if(!tree[p][s[i]]) return 0;
		p = tree[p][s[i]];
	}
	return cnt[p];
}
void init(){
	for(int i = 0; i <= tot; i++){
		for(int j = 0;j <= 65; j++){
			tree[i][j] = 0;
			
		}
		cnt[i] = 0;
	}
	tot = 0;
}
int n,q;

void solve(){
	init();
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		add(s);
	}	
	while(q--){
		string s;
		cin >> s; 
		cout<< ask(s) << endl;
	} 
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
