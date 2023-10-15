#include<bits/stdc++.h>

using namespace std;
int n = 500000;
int q = 500000;
int a[500005];
mt19937 rnd(time(0));
int main(){
	freopen("C10.in","w",stdout);
	srand(time(0));
	cout << n << " " << q << endl;
	for(int i =1;i <= n; i++){
		a[i] = i;
	}
	random_shuffle(a+1,a+1+n);
	for(int i = 1;i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	for(int i = 1;i <= q; i++){
		cout << (rnd()&1);
//		cout << 0;
	}
	return 0;
}
