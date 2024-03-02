#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(time(0));
int n,m;

int main(){
	srand(time(0));
	freopen("animal.in","w",stdout);
	cout << 10 << endl;
	for(int t = 1; t <= 10; t++){	
		n = rand() % 499+2;
		m = rand()%n+1;
		int modn = 1000000000;
		int modm = 100000;
		cout << n << " " << m << endl;
		for(int i = 1; i <= n; i++) cout << (1ll*rnd()%modn*rnd()%modn + modn)%modn+1 << " ";
		cout << endl;
		for(int i = 1;i <= n; i++) cout << (rnd() % modm +modm)%modm+1<< " ";
		cout << endl; 
	}
	return 0;
}
