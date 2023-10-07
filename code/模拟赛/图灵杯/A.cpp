#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const ll INF = 0x3f3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const ll base = 992844353;
using namespace std;
int n;
int s[N];
ll P[N],a[N];
ll f[N][N];

int main(){
	cin >> n;
	P[0] = 1;
	for(int i = 1; i <=  n; i++){
		cin >> s[i];
		P[i] = P[i-1] * base%mod;
		f[i][i] = s[i];
	}
	for(int len = 2; len < n; len++){
		
	}
	return 0;
}
