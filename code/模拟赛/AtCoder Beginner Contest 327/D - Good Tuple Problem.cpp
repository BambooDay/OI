#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n,m;
int a[N],b[N];
int f[N<<1];
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= 2*n; i++) f[i] = i;
	for(int i = 1;i <= m; i++) cin >> a[i];
	for(int i = 1;i <= m; i++) cin >> b[i];
	for(int i = 1;i <= m; i++){
		int fa = find(a[i]),af = find(a[i]+n);
		int fb = find(b[i]),bf = find(b[i]+n);
		if(fa == fb || af == bf){
			puts("No");
			return 0;
		}
		f[fa] = bf;
		f[fb] = af;
	}
	puts("Yes");
	return 0;
}
