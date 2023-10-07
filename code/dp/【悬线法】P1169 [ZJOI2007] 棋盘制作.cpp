#include <bits/stdc++.h>
const int N = 1010;
using namespace std;
int l[N][N],r[N][N],h[N][N],a[N][N],f[N][N],L[N][N],R[N][N];
char ch;
int n, m, tmp, ans1, ans2;

void solve(){
	for(int i = 1;i <= n; i++){
		for(int j= 1; j <= m;j++){
			f[i][j] = l[i][j] = r[i][j] = L[i][j] = R[i][j] =h[i][j] = 0;			
		}
	}
	for(int i = 1;i <= n; i++){
		tmp = 0;
		for(int j = 1;j <= m; j++){
			if(a[i][j]){
				l[i][j] = tmp;
			}else{
				tmp = j,L[i][j] = 0;
			}
		}
		tmp = m+1;
		for(int j = m; j > 0; j--){
			if(a[i][j]){
				r[i][j] = tmp;
			}else{
				tmp = j;
				R[i][j] = m+1;
			}
		}
	} 
	for(int i = 1;i <= m; i++){
		R[0][i] = m+1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1;j<=m; j++){
			if(a[i][j]){
				f[i][j] = min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
				h[i][j] = h[i-1][j] + 1;
				L[i][j] = max(L[i-1][j],l[i][j]);
				R[i][j] = min(R[i-1][j],r[i][j]);
				ans1 = max(ans1,f[i][j]*f[i][j]);
				ans2 = max(ans2, h[i][j] *(R[i][j] - L[i][j] - 1));
			}
		}
	}
}
int main(){
	cin >> n >>m;
	for(int i = 1;i <= n; i++){
		for(int j= 1; j <= m; j++){
			cin >> a[i][j];
			if((i+j)%2 == 0){
				a[i][j] = 1-a[i][j];
			}
		}
	}
	solve();
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] = 1-a[i][j];
		}
	}
	solve();
	cout << ans1 << endl << ans2;
	return 0;
}
