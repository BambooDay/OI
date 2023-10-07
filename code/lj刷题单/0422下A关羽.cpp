#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
map<long long,long long> m;
map<long long,bool> m1;
long long sum = 0;
int cnt = 0;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		m[i] = sum;
		m1[sum] = i;
		cin >> x;
		sum += x;
	}
	for(int i =1;i <= n; i++){
//		cout << m[i] << " " << (m[i]+sum/2)%sum << endl;
		if(m1.count((m[i]+sum/2)%sum)) {
			
			cnt++;
		}
	}
	cnt/=2;
	cout << (cnt-1)*cnt/2;
	return 0;
}
//8 1 2 2 3 1 1 3 3
