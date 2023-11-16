#include<bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int a[N];
int fa[N];
int dfs(int x,int y) {
	if(x == 0) return -1;
	if(__gcd(a[x],a[y]) > 1) return x;
	return dfs(fa[x],y);
}
int n,k;
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n-1; i++) {
		int x,y;
		cin >> x >> y;
		fa[y] = x; 
	}
	for(int i = 1; i <= k; i++) {
		int x,y;
		cin>>x;
		if(x == 1) {
			cin >> y;
			cout << dfs(fa[y],y) << endl;
		} else {
			cin >> x >> y;
			a[x] = y;
		}
	}
	return 0;
}

