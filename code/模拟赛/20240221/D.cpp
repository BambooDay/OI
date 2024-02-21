#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int f[N],s[N],m,n,k;
int fa(int x){ 
	return x == f[x] ? x : f[x] = fa(f[x]); 
}

int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin >> m >> n >> k;
	for(int i = 1;i <= n; i++) f[i] = i;
	while(m--){
		int x,y;
		cin >> x >> y;
		x = fa(x);
		y = fa(y);
		if(x != y) s[y] += s[x],f[x] = y;
		s[y]++; 
	}
	for(int i = 1;i <= n;i++){
		k-= (i==f[i]&&s[i]%2);
	}
	cout << k;
	return 0;
} 

