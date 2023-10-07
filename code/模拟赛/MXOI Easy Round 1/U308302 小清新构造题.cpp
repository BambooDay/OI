#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, k;
int main(){
	cin >> n >> k;
	if(k%2 == 0) {
		puts("No");
		return 0;
	}
	else puts("Yes");
	if(n == 1){
		cout << 2 << " " << 1;
		return 0;
	}
	cout << 2*n << " " << 2*n - k << endl;
	for(int i = 1 ,f = 0; i <= 2*n; i++){
		if(i == 2*n || i == 2*n-k) continue;
		if(f) {
			cout << i;
			cout << endl;
		}else{
			cout << i << " ";
		}
		f = !f;
	}
	for(int i = 1;i <= (n-1)/2; i++){
		cout << 1 << " " << 1 << endl;
	}
	int cnt = (n - 1) / 2;
	while(cnt > 1){
		cout <<"0 0" << endl;
		cnt--; 
	}
	cout << 0 << " " << k;
	return 0;
}
