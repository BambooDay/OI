#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
ll a[N];
ll sum1 = 0, sum2 = 0;
int main(){

	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		cin >> a[i];
		if(n == 2){
			if(i % 2 == 0) sum1 += a[i];
			if(i % 2) sum2 += a[i];
			continue;
		}
		if(i % 2 == 0 && a[i] > 0) sum1 += a[i];
		if(i % 2 && a[i] > 0) sum2 += a[i];
	}
	cout << max(sum1,sum2);
	return 0;
}
