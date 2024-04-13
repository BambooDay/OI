#include <bits/stdc++.h>
const int N = 1005;

using namespace std;
int n,m,q;
int r[N][N],c[N][N];
int a[N][N];
int main(){
	freopen("present.in","r",stdin);
	freopen("present.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= n; i++){
		for(int j =1; j <= m; j++){
			int x;
			scanf("%d",&x);
			a[i][j] = x;			
			r[i][j] = c[j][i] = x;
		}
	}	
	for(int i = 1;i <= n; i++){
		sort(r[i]+1,r[i]+1+m,greater<int>());
	}
	for(int i = 1; i <= m; i++){
		sort(c[i]+1,c[i]+1+n,greater<int>());
	}
	while(q--){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		int num = a[x][y];
		int nr = 1,nc = 1;
		int ans = 0;
		while(k--){
			if(r[x][nr] == num) nr++;
			if(r[x][nr] > c[y][nc]) {
				ans = r[x][nr];
				nr++;
			}else{
				ans = c[y][nc];
				nc++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
