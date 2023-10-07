#include <bits/stdc++.h>
const int N = 1010;

using namespace std;
double F[N][N];
int n, m, x, y;
double M[N][N];
void build(int lin){
	M[1][1] = M[m][m] = 2;
	M[1][2] = M[m][m-1] = -1;
	M[1][m+1] = F[lin+1][1] + 3;
	M[m][m+1] = F[lin+1][m] +3;
	for(int i = 2; i < m; i++){
		M[i][i-1] = M[i][i+1] = -1;
		M[i][i] = 3,M[i][m+1] = F[lin+1][i] + 4; 
	}
}
void gauss(int lin){
	for(int i = 1;i <= m; i++){
		double k = M[i+1][i] / M[i][i];
		M[i+1][i] = 0,M[i+1][i+1] -= M[i][i+1]*k;
		M[i+1][m+1] -= M[i][m+1] *k;
	}
	F[lin][m] = M[m][m+1] / M[m][m];
	for(int i = m-1; i > 0; i--){
		F[lin][i] = (M[i][m+1] - F[lin][i+1]*M[i][i+1])/M[i][i];
	}
}
int main(){
	cin >> n >> m >> x  >> y;
	if(m==1)return cout << (n-x)*2 << endl,0;
	for(int i = n-1; i >= x; i--){
		build(i);
		gauss(i);
	}
	cout <<fixed << setprecision(10)<< F[x][y];
	return 0;
}
