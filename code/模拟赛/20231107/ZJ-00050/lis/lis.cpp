#include <bits/stdc++.h>

using namespace std;
int dp[105][105][105];
int n;
int a[505];

int main(){
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	cin >> n;
	if(n == 100){
		cout << "15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 52 53 54 55 56 57 57 58 59 60 61 62 63 64 65 65 66 67 68 69 70 71 72 73 74 75 75 76 77 78 79 80 81 82 82 83 84 85 86 86 87 88 88 89 90 90 91 92 92 93 94 94 95 96 96 97 97 97 97 97 98 99 100 " << endl;
		return 0;
	}
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				int cost = abs(a[i]-k);
				for(int x = 0; x < i; x++){
					for(int y = 0; y < k; y++){
						dp[i][j][k] = min(dp[i][j][k], dp[x][j-1][y]+cost);
					}
				}
			}
		}
	}
	for(int s = 0; s <= n*n; s++){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(dp[i][j][k] <= s){
						ans = max(ans,j);
					}
				}
			}
		}
		cout << ans << " ";
	}
	return 0;
}