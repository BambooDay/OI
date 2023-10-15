#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

signed main(){
	freopen("qidong.in","r",stdin);
	freopen("qidong.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = n-2; i; i--){
			if(i*i % n == 1){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}