#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string a, b;
int main(){
	cin >> a >> b;
	a = a.substr(a.find('.'));
	b = b.substr(b.find('.'));
	if(a == b) cout << "YES";
	else cout << "NO";
	return 0;
}
