#include <bits/stdc++.h>

using namespace std;
int t;

int main(){
	cin >> t;
	while(t--){
		int n,p;
		cin >> n >> p;
		if((n-1)/2 < p){
			cout << -1 << endl;
			continue;
		}
		n -= p*2+1;
		for(int i = 1; i <= n; i++) cout << 0;
		cout << 1;
		for(int i = 1; i <= p; i++) cout <<"01";
		cout << endl;
	}	
	return 0;
} 
