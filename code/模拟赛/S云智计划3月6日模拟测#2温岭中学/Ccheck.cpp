#include <bits/stdc++.h>

using namespace std;
int g[505][505];
int n;
int sum = 0;
int main(){
	freopen("graph.out","r",stdin);
	freopen("check.out","w",stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			cin >> g[i][j];
			g[j][i] = g[i][j];
		}
	}	
//	for(int i = 1;i <= n; i++){
//		for(int j = 1;j <= n; j++){
//			cout << g[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= n; i++){
		for(int j = i+1; j <= n; j++){
			for(int k = j+1; k <= n; k++){
				if(g[i][j] && g[j][k] && g[k][i]) sum++;
			}
		} 
	}
	freopen("graph.in","r",stdin);
	cin >> n;
	if(sum == n){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}
