#include <bits/stdc++.h>
const int mod = 1e9+7;
const int N = 2e3+10;
#define int long long
using namespace std;
map<string,int> m;
int num[N],cnt = 0;
int n;
int f[N][N];
int k;
int C[N][N];
void init(){
	C[0][0] = 1;
	for(int i = 1; i <= 2000; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++){
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
}
signed main(){
	init();
	cin >> n >> k;
	for(int i = 1 ;i <= n; i++){
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		if(!m.count(s)){
			m[s] = ++cnt;
		}
		int id = m[s];
		num[id]++;
	}	
	f[0][0] = 1;
	for(int i = 1; i <= cnt; i++){
		for(int j = 0; j <= k; j++){
			for(int x = 0; x <= num[i]&&x*(x-1)/2<=j; x++){
				f[i][j] = (f[i][j] + (f[i-1][j-x*(x-1)/2]*C[num[i]][x])%mod)%mod;
			}
		}
	}
	cout << f[cnt][k];
	return 0;
}
