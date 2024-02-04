#include <bits/stdc++.h>
const int N = 605;

using namespace std;
char mp[N][N];
int n,m;
int val[N][N];
long long sum = 0;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
		}
	}	
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mp[i][j] == '#') continue;
			for(int &k = val[i][j] = 1,flag = 1;flag;k++){
				if(i+k > n || i-k <= 0||j+k > m||j-k <= 0)break;
				for(int x = i-k; x <= i+k; x++){
					if(mp[x][j-k] == '#') {
						flag = 0;
						break;
					}
				} 
				for(int x = i-k; x <= i+k; x++){
					if(mp[x][j+k] == '#'){
						flag = 0;
						break;
					} 
				}
				for(int y = j-k; y <= j+k; y++){
					if(mp[i-k][y] == '#'){
						flag = 0;
						break;
					}
				}		
				for(int y = j-k; y <= j+k; y++){
					if(mp[i-k][y] == '#'){
						flag = 0;
						break;						
					}
				}		
			} 
			cout << val[i][j] << " ";
			sum += val[i][j]*val[i][j];
		}
		cout << endl;
	}
	cout << sum << endl;	
	return 0;
}
