#include <bits/stdc++.h>
const int N = 5005;

using namespace std;
int a[N],b[N];
int n;
int ans = 1e9,k = 1;
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		char ch;
		cin >> ch;
		a[i] = (ch == 'F');
	}
	for(int i = 1;i <= n; i++){
		int tag = 0,cnt = 0;
		memset(b,0,sizeof b);
		for(int j = 1;j <= n; j++){
			tag ^= b[j];	
			int now = a[j]^tag;
			if(now) continue;
			if(j+i-1 > n){
				cnt = 1e9;
				break;
			}
			b[j+1] ^= 1;
			b[j+i] ^= 1;
			cnt++;		
		}
		if(cnt < ans) {
			ans = cnt;
			k = i;
		}
	}
	cout << k << " " << ans;
	return 0;
}
