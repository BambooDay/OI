#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int t = 5e5-42767;
int main(){
	freopen("p15.in","w",stdout);
	srand(time(0));
	t += rand();
	cout << t << endl;
	cout << 1 << " " << 12365 << endl;
	t--;
	while(t--){
		ll n = 1e11 + rand();
		cout << n << " ";
		int l = 1e5-40000 + rand();
		cout << l << endl;
	}
	return 0;
}//32767
