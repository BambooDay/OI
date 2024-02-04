#include <bits/stdc++.h>

using namespace std;
string s1 = "acoipp",s2 = "svpoll";
string s;
int main(){
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >='A' && s[i] <= 'Z') s[i] = 'a'+s[i]-'A';
	}
	if(s == s1) puts("Luogu");
	else if(s == s2) puts("Genshin");
	else puts("Boring");
	return 0;
} 
