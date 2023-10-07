#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		sum += a-1;
//		if(sum >= n){
//			puts("YES");
//			return ;
//		}
		if(a == 1) cnt++; 
	}
	if(n == 1){
		puts("NO");
		return;
	}
	if(sum < cnt){
		puts("NO");
	} else{
		puts("YES");
	}
}
signed main(){
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
