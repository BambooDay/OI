#include <bits/stdc++.h>
const int N = 2005;

using namespace std;
int n,m;
int a[N][N],b[N][N],c[N][N],t[N][N];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n*2; i++){
		for(int j = 1; j <= m*2; j++){
			cin >> a[i][j];
		}
	}	
	for(int i =1;i <= n*2; i +=2){
		for(int j = 1; j <= m*2; j+=2){
			c[i/2+1][j/2+1] = a[i][j] + a[i][j+1]+a[i+1][j]+a[i+1][j+1];
		}
	}

	for(int i = 1; i<= m; i++){
		for(int j = 1; j <= n; j++){
//			t[i][j] = c[j][i];
			cout << c[j][i] << " ";
		}
		cout << endl;
	}
//	for(int i = 1; i <= m; i++){
//		for(int j = 1; j <= n; j++){
//			cout << t[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
}
