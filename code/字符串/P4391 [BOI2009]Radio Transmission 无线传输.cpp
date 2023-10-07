#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const ull base = 13331;
using namespace std;
int L;
string s;
ull a[N],P[N];
ull get(int l, int r){
	return a[r]  - a[l] * P[r-l];
}
int main(){
	cin >> L >> s;
	P[0] = 1;
	for(int i = 0; i < L; i++){
		a[i+1] = a[i] * base + s[i];
		P[i+1] = P[i] * base;
	}

	for(int i = 1; i <= L; i++){
		if(get(i,L) == get(0,L-i)){
			cout << i;
			exit(0);
		}
	}
	return 0;
}
