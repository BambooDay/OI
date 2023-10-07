#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n , t;
ll k;
int a[N],ans[N];
int main(){
	cin >> n >> k >> t;
	for(int i = 1; i <=n; i++){
		a[i] = i;
		ans[i] = i;
	}
	for(int i = 1; i <= t; i++){
		int b[N];
		for(int i = 1;i <= n; i++){
			cin >> b[i];
			b[i] = a[b[i]];
		}
		for(int i = 1; i<= n; i++){
			a[i] = b[i];
		}
	}
	int cnt = -1;
	for(int i =1; i <= k; i++){
		int c[N];
		for(int i = 1;i <= n; i++){
			c[i] = ans[a[i]];
		}
		bool f = 1;
		for(int i = 1;i <= n; i++){
			ans[i] = c[i];
			if(ans[i] != i) f = 0;
		}
		if(f){
			cnt = i;
			break;
		}
	}
//	cout<< cnt << endl;
	if(cnt != -1 && k % cnt !=0){
		for(int i = 1; i <= k % cnt; i++){
			int c[N];
			for(int i = 1;i <= n; i++){
				c[i] = ans[a[i]];
			}
			for(int i = 1;i <= n; i++){
				ans[i] = c[i];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
/*
5 2 3
1 2 5 4 3
2 3 4 5 1
5 2 4 3 1
*/
