#include <bits/stdc++.h>

using namespace std;
int n = 1000000;
mt19937 rnd(time(0));
int main(){
	freopen("B10.in","w",stdout);
	cout << n << endl;
	for(int i = 1;i <= n; i++){
		cout << (rnd()&1);
	}
	return 0;
}
