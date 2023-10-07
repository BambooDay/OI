#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string s1,s2;
int len1,len2;
int ne1[N],ne2[N];

int main(){
	cin >> s1 >> s2;
	len1 = s1.size(),len2 = s2.size();
	s1 = " "+s1,s2 = " "+s2;
	ne2[1] = 0;
	for(int i = 2; i <= len2; i++){
		int p = ne2[i-1];
		while(s2[p+1] != s2[i] && p){
			p = ne2[p];
		}
		if(s2[p+1] == s2[i]) ne2[i] = p+1;
	}
	for(int i = 1; i <= len1; i++){
		int p = ne1[i-1];
		while(s2[p+1] != s1[i] && p!=0){
			p = ne2[p];
		}
		if(s2[p+1] == s1[i]) ne1[i] = p+1;
		if(ne1[i] == len2) cout << i - len2+1<<endl;
	}
	for(int i = 1; i <= len2; i++){
		cout << ne2[i] << " ";
	} 
	return 0;
}

