#include <bits/stdc++.h>


using namespace std;
int n;
string s;

int main(){
	cin >> n >> s;
	for(int i = 0; i< s.size(); i++){
		if(s[i] == 'a' && s[i+1] == 'b' || s[i] =='b' && s[i+1] == 'a'){
			puts("Yes");
			return 0;
		}
	}	
	puts("No");
	return 0;
}
