#include <bits/stdc++.h>
#define int long long
using namespace std;
map<long long , int > m;
int n;
int sum;
int res = 0;
signed main(){
	cin >> n;
	for(int  i = 1; i <= n; i++){
		int a;
		cin >> a;
		sum ^= a;
		if(m.count(sum)){
			res += m[sum];
//			cout << m[sum] << endl;
			m[sum]++;
		}else{
			m[sum] = 1;
		}
		if(!sum) res++;
//		cout << sum << endl;
	}
	cout << res;
	return 0;
}
