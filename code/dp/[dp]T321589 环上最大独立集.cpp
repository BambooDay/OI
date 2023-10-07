#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int ll
const int N = 2e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;
int n;
int a[N],f[N][3],f1[N][3];
int ans = -INF;
signed main(){
	cin >> n;
	memset(f,-0x3f,sizeof f);
	memset(f1,-0x3f,sizeof f1);
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int k = 1; k <= n; k++){
		#define K k+n-1
		f[k][0] = 0;
		f[k+1][0] = 0,f[k+1][1] = a[k+1];
		f1[k][1] = a[k];
		f1[k+1][0] = a[k];
		f1[k+2][0] = a[k];
		f1[k+2][1] = a[k] + a[k+2];
		for(int i = k+2; i <= K; i++){
			f[i][1] = f[i-1][0] + a[i];
			f[i][0] = max(f[i-1][0], f[i-1][1]);
			if(i >= k + 3){
				f1[i][1] = f1[i-1][0] + a[i];
				f1[i][0] = max(f1[i-1][0], f1[i-1][1]);
				if(i == K){
					f1[i][1] = -INF;
				}	
			}
		}
		ans = max(ans,max(f[K][0],f[K][1]));
		ans = max(ans,max(f1[K][0],f1[K][1]));
		break;		
	}
	cout << ans;
	return 0;
}
