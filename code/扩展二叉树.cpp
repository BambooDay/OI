#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string s;
int Left[30],Right[30];
char val[30];
int idx,cnt;//idx表示节点编号，cnt是在前序遍历中的下标 
void build(int i){
	if(++cnt == s.size()) return;
	val[i] = s[cnt];
	if(s[cnt] == '.') return;
	Left[i] = ++idx;
	build(Left[i]);
	Right[i] = ++idx;
	build(Right[i]);
}
void mid(int i){
	if(val[i] == '.'){
		return;
	}
	mid(Left[i]);
	cout << val[i];
	mid(Right[i]);
}
void esi(int i){
	if(val[i]=='.'){
		return;
	}
	esi(Left[i]);
	esi(Right[i]);
	cout << val[i];
}
int main(){
	cin >> s;
	s = " " + s;
	build(0);
	mid(0);
	puts(""); 
	esi(0);
	return 0;
}
