#include<bits/stdc++.h>
using namespace std;
int n,a[105],f[105][15][15][15];
int dfs(int g[4], int x) {
	if(f[x][g[1]][g[2]][g[3]] != 0) return f[x][g[1]][g[2]][g[3]];
	if(g[1]==0 && g[2]==0 && g[3] == 0) return 0;
	int num = 1e9; 
	for(int i = 1; i <= 3; i++){
		if(g[i]!=0){
			int t1 = g[1],t2 = g[2],t3 = g[3], j, t = g[i];
			g[i] = 0;
			for(j = x; j <= x+t-1 && j <= n; j++) g[a[j]]++;
			num = min(num,dfs(g,j));
			g[1] = t1, g[2] = t2,g[3] = t3;
		}
	}
	num++;
	f[x][g[1]][g[2]][g[3]] = num;
	return num;
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		if(ch == 'A') a[i] = 1;
		if(ch == 'B') a[i] = 2;
		if(ch == 'C') a[i] = 3;
	}
	int g[4]= {0};
	for(int i = 1; i <= min(10,n); i++) g[a[i]]++;
	cout << dfs(g,min(10,n)+1) << endl;
	return 0;
}

