#include <bits/stdc++.h>
const int N = 200;
using namespace std;
int n, a[N];
int sum = 0;
void solve(){
	cin >> n;
	sum = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1;i <= n; i++){
		if(a[i] > sum/2){
			puts("T");
			return;
		}
	}
	sum%2 ? puts("T") : puts("HL");
} 
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
