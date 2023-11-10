#include <bits/stdc++.h>

using namespace std;
int n,m;
double sc;
double s;
int a,b,c,d;
int main(){
	cin >> n >> s >> m;
	sc = (10000000.0)/n*1.0;
	a = n-m;
//	s -= sc*(n-m);
//	cout << s << endl;
	bool f = 1;
	for(int i = 0; i <= a && f; i++){
		for(int j = 0; j <= m&&f; j++){
			if(int(sc*j/2.0+i+sc*a*1.0) == int(s)){
				b = i,c = j,d = m-j;
				f = 0;
			}
		}
	}
	printf("p%d(+%d) f%d l%d",a,b,c,d);
	return 0;
}
