#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
int a[M];
int dis[M];
int main(){
	cin >> n;
	ll sum = 0;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		dis[a[i]] = abs(a[i] - i);
		sum += abs(a[i] - i) % 520;
		sum %= 520;
	}
	for(int i =1;i <= n; i++) cout << dis[i] << ' ';
	cout << endl << sum%520;
	return 0;
}
