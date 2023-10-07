#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(time(0));
int main(){
	freopen("party.in","w",stdout);
	int n = rnd() % 20 + 1;
	cout << n << endl;
	for(int i =1;i <= n; i++){
		int a = rnd() % 15;
		cout << a << " ";
	}
	return 0;
}
