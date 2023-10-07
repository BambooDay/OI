#include <bits/stdc++.h>
#define int long long
const int N = 150005;
using namespace std;
int n, m;
int a[N];
int p[400][400];

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		for(int j = 1; j <= sqrt(n); j++){
			p[j][i%j] += a[i];
		}
	}	
	while(m--){
		char op;
		cin >> op;
		int x, y;
		cin >> x >> y;
		if(op == 'A'){
			if(x <= sqrt(n)){
				cout << p[x][y] << endl;
			}else{
				int ans = 0;
				for(int i = y; i <= n; i += x) ans += a[i];
				cout << ans << endl;
				
			}
		}else{
			for(int i = 1; i <= sqrt(n); i++){
				p[i][x%i] += y-a[x];
			}
			a[x] = y;
		}
	}
	return 0;
}
