#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int n;
int a[N];
int main(){
	cin >> n;
	bool flag = 1;
	int low = 1e9;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		low = min(low,a[i] & -a[i]);
		if(a[i] % 2 == 0) flag = 0;
	}
	if(n % 2 == 0){
		cout << 1 << endl;
		for(int i =1;i <= n; i++){
			cout<< (i&1);
		}
	}else if(flag){
		puts("-1");
	}else{
		int cnt1 = 0,cnt2 = 1,flag = 0;
		int sum = 0;
		for(int i = 1;i <= n; i++){
			a[i] /= low;
			sum += a[i] % 2;
		}
		if(sum % 2){
			puts("-1");
			return 0;
		}
		cout << 2*low << endl;
		int cnt = 0;
		for(int i = 1;i <= n; i++){
			if(a[i] % 2){
				if(flag < 2) flag++,a[i] = 0;
				else a[i] = cnt1,cnt1 ^= 1;
			}else{
				a[i] = cnt2, cnt2 ^= 1;
			}
		}
		for(int i = 1; i <= n; i++){
			cout << a[i];
		}
	}
	return 0;
}
