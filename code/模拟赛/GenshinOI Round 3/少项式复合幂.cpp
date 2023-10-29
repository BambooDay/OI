#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int m,q,p;
int ksm(int a, int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans = ans * a % p;
		}
		a = a*a%p;
		b >>= 1;
	}
	return ans;
}
int a[30],b[30];
int f[N];
int get(int x){
	int ans = 0;
	for(int i = 1; i <= m; i++){
		ans = (ans + a[i]*ksm(x,b[i])%p) % p;
	}
	return ans;
}
bool vis[N];
int belong[N];
vector<int> e[N];
int fa[N][30]; 
void init(){
	for(int i = 0; i < p; i++){
		fa[i][0] = get(i);
	}
	for(int i = 1;i <= 25; i++){
		for(int j = 0; j < p; j++){
			fa[j][i] = fa[fa[j][i-1]][i-1];
		}
	}
}
signed main(){
	cin >> m >> q >> p;
	for(int i = 1; i<= m; i++){
		cin >> a[i] >> b[i];
		a[i] %= p;
	} 
	init();
	while(q--){
		int x,y;
		cin >> x >> y;
		x %= p;
		for(int i = 25; i >= 0; i--){
			if((1 << i) <= y) x = fa[x][i],y -= (1<<i);
		}
		cout << x << endl;
	}
	return 0;
}
