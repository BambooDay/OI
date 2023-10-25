#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
int up[N],dn[N],lt[N],rt[N];
int n,m;

signed main(){
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		char ch;
		cin >> ch;
		up[i] = up[i-1];
		dn[i] = dn[i-1];
		lt[i] = lt[i-1];
		rt[i] = rt[i-1];
		if(ch == 'W') up[i]++;
		if(ch == 'S') dn[i]++;
		if(ch == 'A') lt[i]++;
		if(ch == 'D') rt[i]++;  
	}
	int x = 0,y = 0;
	while(m--){
		int l, r;
		cin >> l >> r;
		if(abs(x + (rt[r]-rt[l-1])) >= abs(x-(lt[r]-lt[l-1]))){
			x = x + (rt[r]-rt[l-1]);
		}else{
			x = x-(lt[r]-lt[l-1]);
		}
		if(abs(y+(up[r]-up[l-1])) >= abs(y-(dn[r]-dn[l-1]))){
			y = y+(up[r]-up[l-1]);
		}else{
			y = y-(dn[r]-dn[l-1]);
		}
	}
	cout << x << " " << y << endl;
	return 0;
}