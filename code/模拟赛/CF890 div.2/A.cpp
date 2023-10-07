#include <bits/stdc++.h>

using namespace std;
int a[60];
int n;
bool check(int x){
	for(int i = x+1; i <= n; i++){
		if(a[i] < a[i-1]) return 0;
	} 
	return 1;
} 
void solve(){
//	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = 0;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			r = mid-1;
			ans = mid;
		}else{
			l=  mid+1;
		}
	}
	int ma = 0;
	for(int i = 1; i < ans; i++) ma = max(a[i],ma);
	cout << ma << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
