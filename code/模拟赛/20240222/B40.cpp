#include <bits/stdc++.h>
const int N = 4005;

using namespace std;
int n,m,x,k;
int a[N],b[N],c[N*N];
int cnt = 0;
signed main(){
	freopen("python.in","r",stdin);
	freopen("python.ans","w",stdout);
	cin >> n >> m >> x >> k;
	for(int i = 0;i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	for(int i = 0; i < min(n,m-x); i++){
		for(int j = i+x; j < m; j++){
			c[++cnt] = a[i]*b[j];
		}
	}	
	sort(c+1,c+1+cnt);
	cout << c[k] << endl; 
	return 0;
}
