#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
ull a[N];
int n;
map <ull,bool> m;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		ull h = 1;
		for(int j = 0; j < s.size(); j++){
			h = h * 10 + (s[j] - '0') * 13331;
		}
		if(!m.count(h)) m[h] = 1;
	}
	cout << m.size();
	return 0;
}

