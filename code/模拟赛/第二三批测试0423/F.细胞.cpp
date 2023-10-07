#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m;
char a[1005][1005];
int cnt = 0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i =1; i <= n; i++){
		scanf("%s",1+a[i]);
			
	}
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1) a[i-1][j] = a[i][j];
			if(i == n) a[i+1][j] = a[i][j];
			if(j == 1) a[i][j-1] = a[i][j];
			if(j == m) a[i][j+1] = a[i][j];
			if(a[i][j] == a[i-1][j] && a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1] && a[i][j] == a[i][j-1]){
				cnt++;
			}
//			cout << a[i][j];
		}
//		cout << endl;
	}
	printf("%d",cnt);
	return 0;
}
