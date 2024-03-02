#include <bits/stdc++.h>
const int N = 505;

using namespace std;
int mp[N][N];
int L[N][N],R[N][N];
int n,m;

int main(){
	freopen("map.in","r",stdin);
	freopen("map.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
		}
	}	
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j]){
				L[i][j] = L[i][j-1]+1;
			}
		}
		for(int j = m; j >= 1; j--){
			if(mp[i][j]){
				R[i][j] = R[i][j+1]+1;
			}
		}
	}
	long long ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= m; j++){
			if(!mp[i][j] || !mp[i+1][j]) continue;
			for(int k = 1; i+k <= n; k++){
				if(!mp[i+k+1][j] || L[i+k][j] <= k || R[i+k][j] <= k){
					ans += k;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
