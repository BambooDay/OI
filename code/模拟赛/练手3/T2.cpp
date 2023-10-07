#include <bits/stdc++.h>
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int a[15];
int b[15][15];
int sum = 0,cnt[15];
int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		bool f = 1;
		for(int i = 1; i <= sum; i++){
			bool flag = 1;
			for(int j = 1; j <= cnt[i];j++){
				if(__gcd(b[i][j],x) != 1){
					flag = 0;
					break;
				}
			}
			if(flag){
				b[i][++cnt[i]] = x;
				f = 0;
				break;
			}
		}
		if(f){
			b[++sum][++cnt[sum]] = x;
		}
	}
	cout << sum << endl;
	return 0;
}

