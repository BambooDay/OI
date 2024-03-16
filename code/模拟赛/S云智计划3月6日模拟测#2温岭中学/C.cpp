#include <bits/stdc++.h>
const int N = 505;

using namespace std;
int n;
int g[N][N];
int x = 0;
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin >> n;
	while(n){
		int now = 3;
		while(now*(now-1)*(now-2)/6 <= n) now++;
		now--;
		n -= now*(now-1)*(now-2)/6;
		for(int i = 1; i <= now; i++){
			for(int j = 1; j <= now; j++){
				g[x+i][x+j] = 1;
			}
		} 
		x += now;
	}	
	cout << x << '\n';
	for(int i = 1; i < x; i++){
		for(int j = i+1; j <= x; j++){
			if(g[i][j]) printf("1 ");
			else printf("0 ");
		}
		puts("");
	}
	return 0;
}
