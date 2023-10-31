#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
int trie[30][50*N],idx;
int v[N*50*30];
void add(string s,int len){
	int p = 0;
	for(int i =1; i <= len; i++){
		if(!trie[s[i]-'a'][p]){
			trie[s[i]-'a'][p] = ++idx;
		}
		p =trie[s[i]-'a'][p];
	}
	v[p] = 2;
}
void solve(string s, int len){
	int p = 0;
	for(int i = 1; i<= len; i++){
		if(!trie[s[i]-'a'][p]){
			cout << "WRONG" << endl;
			return;
		}		
		p = trie[s[i]-'a'][p];
	}
	if(v[p] == 2){
		puts("OK");
		v[p]--;
	}else if(v[p] == 1){
		puts("REPEAT");
	}else{
		puts("WRONG");
	}
}
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		string s;
		cin >> s;
		add(" "+ s,s.size());
	}
	int m;
	cin >> m;
	while(m--){
		string s;
		cin >> s;
		solve(" "+ s,s.size());
	}
	return 0;
}
