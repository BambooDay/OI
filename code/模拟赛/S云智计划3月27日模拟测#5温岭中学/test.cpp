#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
int n, m, a[maxn];
struct matrix {
	ll a[105][105];
	void I() {
		for(int i = 1; i <= 101; i++) a[i][i] = 1;
	}
	matrix() {
		memset(a, 0, sizeof(a));
	}
	matrix operator * (const matrix &x) const {
		matrix res;
		for(int i = 1; i <= 101; i++)
			for(int k = 1; k <= 101; k++) {
				ll t = a[i][k];
				for(int j = 1; j <= 101; j++)
					res.a[i][j] = (res.a[i][j] + t * x.a[k][j]) % mod;
			}
		return res;
	}
} change, ans;
matrix ksm(matrix x, int y) {
	matrix res;
	res.I();
//	for(int i = 1; i <= 101; i++){
//		for(int j = 1; j <= 101; j++){
//			cout << res.a[i][j] << " ";
//		}
//		cout << endl;
//	}
	while(y) {
		if(y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}
int main() {
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		change.a[1][a[i]]++;
		change.a[101][a[i]]++;
	}
	for(int i = 2; i <= 100; i++) change.a[i][i - 1] = 1;
	change.a[101][101] = 1;
	memset(ans.a, 0, sizeof(ans.a));
	ans.a[1][1] = 1;
	ans.a[101][1] = 1;
	
//	cout << m << endl;
	ans = ksm(change, m) * ans;
	cout << ans.a[101][1] << '\n';
	return 0;
}
