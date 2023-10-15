#include <bits/stdc++.h>

using namespace std;
int n = 7500;
int m = 50;
int v[55];
mt19937 rnd(time(0));
int main(){
	freopen("D10.in","w",stdout);
	cout << n << " " << m << endl;
	for(int i = 1; i <= n; i++){
		int siz = rnd() % m+1;
		cout << siz << " ";
		memset(v,0,sizeof v);
		for(int j = 1; j <= siz; j++){
			int x = rnd() % m+1;
			while(v[x]) x = rnd() % m+1;
			v[x] =1;
			cout << x << " ";
		}
		cout << endl;
		
	} 
	return 0;
}
