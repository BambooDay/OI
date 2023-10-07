#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
void solve(){
	ll n;
	cin >> n;
	ull ans = 1;
	if(n % 2){
		for(int i =2;i <= n; i+=2){
			ans *= i;
		}
		cout << ans*2 << endl;
	}else{
		for(int i =1;i <= n; i+=2){
			ans *= i;
		}
		cout << ans*2 << endl;	
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
