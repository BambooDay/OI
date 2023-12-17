#include <bits/stdc++.h>
const int N = 200;

using namespace std;
int n, m;
map<int,int> num;
int a[N];
int ans[N];
int main(){
	freopen("div.in","r",stdin);
	freopen("div.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m; i++) cin >> a[i];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j*j <= a[i]&&j<=n; j++){
			if(a[i]%j == 0){
				num[j]++;
				if(j*j != a[i]&&a[i]/j <= n){
					num[a[i]/j]++;
				}
			}
		}
	}	
	for(auto i : num){
		ans[i.second]++;
	}
	cout << n - num.size() << endl;
	for(int i = 1;i <= m; i++) cout << ans[i] << endl;
	return 0;
}
