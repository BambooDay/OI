#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> e[300];
int val[300];
int f[300][300];//第 i 个点，攻克了 j 个城堡
void dp(int pos){
//	cout << pos-1 << endl;
	f[pos][1] = val[pos];
//	f[pos][0] = 0;
	for(int to : e[pos]){
		dp(to);
		for(int i = m+1; i > 0; i--){
			for(int j = 0; j< i; j++){
				f[pos][i] = max(f[pos][i],f[pos][i-j] + f[to][j]);
//			cout << pos-1 << " " << i << " " << j << " " << f[pos][i-j] << " " << f[to][j] << endl;
			}
		}
	}
//	for(int i = 1;i <= m; i++) f[pos][i] += val[pos];
}
int main(){
	cin >> n >> m;
	memset(f,-1,sizeof(f));
//	cout<< f[1][m] << endl;
	for(int i = 1; i <= n; i++){
		int a,b;
		cin >> a >> b;
		val[i+1] = b;
		e[a+1].push_back(i+1);
	}
	dp(1);
	cout << f[1][m+1];
	return 0;
}
/*
7 4
2 2
0 1
0 4
2 1
7 1
7 6
2 2
*/ 
