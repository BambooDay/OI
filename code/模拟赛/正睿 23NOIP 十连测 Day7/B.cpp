#include<bits/stdc++.h>
const int N = 1e5+10;
const int M = 27;
#define int long long
using namespace std;
int n,m;
int a[N][M];
int b[M];
int ans = 1e18;

signed main(){
	freopen("buy.in","r",stdin);
	freopen("buy.out","w",stdout);
	double st = clock();
//	cin >> n >> m;
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
//			cin >> a[i][j];
			scanf("%lld",&a[i][j]);
		}
	}	
	for(int i = 1; i <= m; i++) scanf("%lld",&b[i]);//cin >> b[i];
	for(int i = 1; i < (1<<m); i++){
		vector<int> id;
		int sum = 0;
		for(int j = 0; j < m; j++){
			if(i&(1<<j)) id.push_back(j+1),sum += b[j+1];
		}
		for(int j = 1;j <= n; j++){
			int mi = 1e18;
			for(int k : id){
				mi = min(a[j][k],mi);
			}
			sum += mi;
		}
		ans = min(ans,sum);
		if(double(clock()-st)/CLOCKS_PER_SEC >= 3.9) break;
	}
//	cout << ans << endl;
	printf("%lld",ans);
	return 0;
}
