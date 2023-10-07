#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int c[N][N],cnt[N][N];
int t, k;

int main(){
	cin >> t >> k;	
	for(int i = 1; i <= 2000;i++) c[i][i] = c[i][0] = 1; 
	
	for(int i = 1; i <= 2000; i++){
		for(int j = 1; j <= i; j++){
			if(j != i) 	c[i][j] = (c[i-1][j-1] + c[i-1][j]) % k;
			cnt[i][j]  = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + !(c[i][j]);
		}
		cnt[i][i+1]=cnt[i][i];
	}
	while(t--){
		int n, m;
		cin >> n >> m;
		if(m > n){
			cout << cnt[n][n] << endl;
		}else{
			cout << cnt[n][m] << endl;
		}
	}
	return 0;
}
