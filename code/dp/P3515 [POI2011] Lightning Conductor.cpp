#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
int h[N],f[N],g[N];
int n;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
	}	
	f[1] = h[1];
	for(int i = 2; i <= n; i++){
		f[i] = max(f[i-1],h[i]);
		for(int j = 0; j*j <= i-1; j++){
			f[i] = max(f[i],h[i-1-(j*j)]+j+1);
		}
	}
	g[n] = h[n];
	for(int i = n-1; i; i--){
		g[i] = max(g[i+1],h[i]);
		for(int j = 0; j*j <= n-i-1; j++){
			g[i] = max(g[i],h[i+(j*j)+1]+j+1);
		} 
	}
	for(int i = 1;i <= n; i++){
		cout << max(f[i],g[i]) - h[i] <<endl; 
	}
	return 0;
}
