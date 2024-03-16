#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
int n,m,a=1,ans,pw[N];

int main(){
	cin >> n >> m;
	pw[0] =1;
	for(int i = 1;i <= n; i++){
		pw[i] = 1ll*pw[i-1]*n%m;
	}	
	for(int i = 1;i <= n; i++){
		ans = (ans + 1ll * a * pw[n-i] % m * (1ll * i * (i-1) / 2 % m)%m) % m;
		a = 1ll*a*(n-i) % m;
	}
	cout << 1ll*ans*n%m << endl;
	return 0;
}
