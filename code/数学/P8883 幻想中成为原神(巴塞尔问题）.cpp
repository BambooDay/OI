#include <bits/stdc++.h>

using namespace std;
int t;
long double pi = acos(-1.0);
int main(){
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		cout << (long long)((1.0-6.0/pi/pi)*n) << endl;
	}
	return 0;
}
