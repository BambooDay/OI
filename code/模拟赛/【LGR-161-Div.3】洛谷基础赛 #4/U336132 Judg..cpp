#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		if(s != "AC"){
			cout << i << " ";
		}
	}	
	return 0;
}
