#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n;
int a[N],b[N];
int solve(){
	cin >> n;
	int suma = 0,sumb = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= n; i++){
		suma += a[i];
		sumb += b[i-1];
		if(sumb < suma) return 0; 
	}
	return n+1;
}
int main(){
	int t;
	cin >> t;
	while(t--) cout << solve() << endl;
	return 0;
}
