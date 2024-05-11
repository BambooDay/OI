#include <bits/stdc++.h>
#define int long long

using namespace std;
int n,m;
vector<vector<int> > a;
int ans1,ans2;
signed main(){
	cin >> n >> m;
	vector<int> tmp(m+10);
	a.resize(n+10,tmp); 
	for(int i =1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			cin >> a[i][j];
		}
	}
//	cout << n << " " << m;
	for(int i = 1;i <= n; i++){
		int mi = 1e18;
		for(int j = 1; j <= m; j++){
			mi = min(mi,a[i][j]);
		}
		for(int j = 1; j <= m; j++){
			if(a[i][j] == mi){
				a[i][j] = 1e18;
				break;
			}
		}
//		cout << mi << " ";
		ans1 += mi; 
	}
//	cout << "\n";
	for(int i = 1; i <= m; i++){
		int mi = 1e18;
		for(int j = 1; j <= n; j++){
			mi = min(mi,a[j][i]);
		}
		ans2 += mi;
	}
	cout << ans1+ans2;
	return 0;
} 
