#include <bits/stdc++.h>

using namespace std;
int a;
int _41,_63,_118;
 
int main(){
	for(int i = 1; i <= 8; i++){
		cin >> a;
		_41 += (a >= 41);
		_63 +=(a>=63);
		_118 +=(a>=118); 
	}
	if(_118){
		cout << 10;
	}else if(_63 >= 4){
		cout << 8;
	}else if(_41 >= 4){
		cout<< 3;
	}else cout << 1;
	return 0;
}
