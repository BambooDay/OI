#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,w[40];
int a[20],b[20];
int ans,suma,sumb;
int mid;
int clac(int x, int y){
	int res = abs(suma-a[x]+a[y] - sumb+a[y]-a[x]);
//	ans = min(ans, res);
	return res;
}
void SA(){
	double t = 2005;
	while(t > 1e-15){
		int x = (int)(rand()) % mid +1,y = n - ((int)(rand()) % (mid+(n%2)));
//		cout << x << " " << y << endl;
		int res = abs(suma - (w[x] << 1) + (w[y] << 1) - sumb);
		double delta = res - ans;
		if(exp(-delta/t) > (double)(rand()/RAND_MAX)){
			ans = min(ans,res);
			suma = suma-w[x]+w[y];
			sumb = sumb-w[y]+w[x];
			swap(w[x],w[y]);
		}
		t *= 0.999;
	}
}
//void SA() { 
//	double Ti = 2004; 
//	while (Ti > 1e-15) {
//		long long x = (int)(rand()) % mid + 1, y = n - ((int)(rand()) % (mid + (n%2)));
////		cout << x << " " << y << endl;
//		long long dis = abs(suma - (a[x] << 1) + (a[y] << 1) - sumb);
//		double D = dis - ans;
//		if (exp(-D/Ti) > (double)(rand()/RAND_MAX)) {
//			ans = min(ans,dis);
//			suma = suma - a[x] + a[y];
//			sumb = sumb - a[y] + a[x];
//			swap(a[x], a[y]);
//		}
//		Ti *= 0.999;
//	}
//}
void solve(){
//	double st = clock();
	cin >> n;
	ans = 0;
	suma=0;
	sumb=0;
	mid = n/2;
	for(int i = 1; i <= n; i++)	{
		cin >> w[i];
		if(i <= mid){
			suma += w[i];	
		}else{
			sumb += w[i];
		}
	}
	if(n == 1){
		cout << w[1] << endl;
		return ;
	}
	ans = abs(suma-sumb);
//	while((clock()-st)/CLOCKS_PER_SEC < 0.04){
	for(int i = 1;i <= 20; i++){
		SA();
	}
//	}
	cout << ans << endl;
}
//void solve(){
//	scanf("%d", &n);
//	mid = n / 2;
////	odd = n % 2;
//	suma = sumb = 0;
//	for (int i = 1; i <= n; ++i) {
//		scanf("%lld", &w[i]);
//		if (i <= mid) s1 += w[i];
//		else s2 += a[i];
//	}
//	if (n == 1) {
//		printf("%lld\n", a[1]);
//		continue;
//	}
//	ans = abs(s1 - s2);
//	for (int i = 1; i < 20; ++i)SA();
//	printf("%lld\n", ans);
//}
signed main(){
	srand(time(0));
//	srand(rand());
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
1
10
5222 91374 22283 85463 31532 31381 70633 66330 67307 192
*/
