#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
string s1, s2;
int ne2[N],ne1[N];
int len1, len2;
int main(){
	cin >> s1 >> s2;
	len1 = s1.size();
	len2 = s2.size();
	s1 = " " + s1;
	s2 = " " + s2;
	ne2[1] = 0; 
	for(int i = 2;i <= len2; i++){
		int p = ne2[i-1];
		while(p && s2[i] != s2[p+1]) p = ne2[p];
		if(s2[i] == s2[p+1]) p++;
		ne2[i] = p;
	}
	for(int i = 1;i <= len1; i++){
		int p = ne1[i-1];
		while(p && s1[i] != s2[p+1]){
			p = ne2[p];
//			cout << p << endl;
		} 
		if(s1[i] == s2[p+1]) p++;
		ne1[i] = p;
		if(ne1[i] == len2){
			cout << i - len2+1 << endl;
		}
//		cout << 111 << endl;
	}
	for(int i =1;i <= len2; i++) cout << ne2[i] << " ";
	return 0;
}
