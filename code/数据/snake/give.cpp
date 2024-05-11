#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
mt19937 rnd(time(0));
int n,m,q,p;
int a[N];
map<int,char> mp;
int mod1 = 1000,mod2=100000;
int main(){
	freopen("snake.in","w",stdout);
	n = rnd()%mod1+1;
	m = rnd()%mod1+1;
	p = rnd()%mod2;
	q = rnd()%mod2;
	cout << n << " " << m << " " << q << " " << p << endl;
	for(int i = 1; i <= q; i++) a[i] = rnd()%mod2+1;
	sort(a+1,a+1+q);
	mp[0] = 'L';
	mp[1] = 'R';
	mp[2] = 'D';
	mp[3] = 'U';
	for(int i = 1; i <= q;i++){
		printf("%d %c\n",a[i],mp[rnd()%4]);
//		cout << a[i] << " " << mp[rnd()%4] << endl;
	}
	for(int i = 1; i <= p; i++){
		printf("%d %d\n",rnd()%n+1,rnd()%m+1);
//		cout << rnd()%n+1 << " " << rnd()%m+1 << endl; 
	}
	cout << rnd()%n+1 << " " << rnd()%m+1 << endl;
	return 0;
}
