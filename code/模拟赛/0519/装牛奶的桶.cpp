#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;

int main(){
	int x, y, M,m;
	cin >> x >> y >> M;
	int cnt = M / x;
	m = M % x;
	if(cnt * y <= M){
		cout << cnt * y;
	}else{
		m %= (y-x);
		cout << M-m;
	}
	return 0;
}
