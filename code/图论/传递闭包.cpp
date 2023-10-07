#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
bitset<N> a[N];
int n;

int main(){
	cin >> n; 
	for(int i = 1;i <= n; i++){
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1; j <= n; j++){
			if(i == j) a[i].set(j);
			int x = s[j] - '0';
//			cin >> x;
			if(x) a[i].set(j);
		}
	}
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n; i++){
			if(a[i][j]){
				a[i] |= a[j];
			}
		}
	}
	int sum = 0;
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= n; j++){
			sum += a[i][j];
//			else cout << "0 ";
		}
//		cout<< endl;
	}
	cout << sum << endl;
	return 0;
}
