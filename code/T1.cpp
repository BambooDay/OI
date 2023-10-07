#include <bits/stdc++.h>
const long long N = 1e13+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
long long t;
int a[N];
int main(){
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		int d,b;
		cin >> d >> b;
		a[d] += b;
	}
	long long ans = 0;
	for(long long i = 1,sum =0; i <= t; i++){
		sum += a[i];
		if(sum){
			sum--;
			ans++;
		} 
	}
	cout << ans << endl;
	return 0;
}

