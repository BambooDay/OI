#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int trie_pre[N][10],trie_suf[N][10];
bitset<N> node[N];//×¢Òâ´óĞ¡ 
int n, m;
map<char,int> val;
int cnt = 0;
void add_pre(string s,int id){
	int p = 0;
	for(int i = 0; i < s.size(); i++){
		if(!trie_pre[p][val[s[i]]]) trie_pre[p][val[s[i]]] = ++cnt;
		p = trie_pre[p][val[s[i]]];
		node[p].set(id,1);
	}
}
void add_suf(string s,int id){
	int p = 0;
	for(int i = s.size()-1; i >=0 ; i--){
		if(!trie_suf[p][val[s[i]]]) trie_suf[p][val[s[i]]] = ++cnt;
		p = trie_suf[p][val[s[i]]];
		node[p].set(id,1);
	}
}
int find(string s, string t){
	int p = 0;
	for(int i = 0; i < s.size(); i++){
		if(trie_pre[p][val[s[i]]]) p = trie_pre[p][val[s[i]]];
		else return 0;
	}
	int q = 0;
	for(int i = t.size()-1; i >=0 ; i--){
		if(trie_suf[q][val[t[i]]]) q = trie_suf[q][val[t[i]]];
		else return 0;
	}
	return (node[p]&node[q]).count();
}

int main(){
	val['A'] = 1;
	val['G'] = 2;
	val['U'] = 3;
	val['C'] = 4;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		add_pre(s,i);
		add_suf(s,i);
	}
	while(m--){
		string s,t;
		cin >> s >> t;
		cout << find(s,t) << endl;
	}
	return 0;
}
/*
2 3
AUGC
AGC
G C
AU C
A C
*/
