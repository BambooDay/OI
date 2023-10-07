#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n,a[1005];

int main(){
	while(cin >> a[++n]); n--;
	ull sum = 0;
	for(int i = 1;i <= n; i++){
		sum += a[i] * pow(2,n-1);
	}
	cout << sum << endl;
	return 0;
}
