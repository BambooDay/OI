#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, st,ml;
int f[60][1005];
int a[60];
int main(){
	cin >> n >> st >> ml;
	f[0][st] = 1;
	for(int i =1;i <= n; i++){
		cin >> a[i];
		for(int j = ml; j >= 0; j--){
			if(j - a[i] >= 0 && f[i-1][j]) f[i][j-a[i]] =1;
			if(j + a[i] <= ml && f[i-1][j]) f[i][j+a[i]] = 1;
			
		}
	}
	for(int i = ml; i >= 0; i--){
		if(f[n][i]){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
