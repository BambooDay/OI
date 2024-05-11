#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n;
int T,M[N];
int a[N];
void solve(int x){
	if(x > a[n]){
		puts("-1");
		return;
	}
//	if(x < a[1]){
//		cout << a[1] << "\n";
//		return;
//	}
	int l = 1,r = n;
	int ans = 0;
	while(l <= r){
		int m = (l+r) >> 1;
		if(a[m] > x && a[m] != 0) ans = m,r = m-1;
		else l = m+1;
	}
	cout << a[ans] << "\n";
	return;
}
signed main(){
//	freopen("2.in","r",stdin);
//	freopen("2.out","w",stdout);
	cin >> n >> T;
	a[0] = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);	
	for(int i = 1; i <= T; i++) cin >> M[i];
	for(int i = 1; i <= T; i++){
		int cnt = 1e18;
		int sum = 0;
		for(int j = 1; j <= M[i]; j++){
			int x;
			cin >> x;
			sum += x;
			cnt = min(cnt,sum);	
		}
		solve(-cnt);
	}
	return 0;
} 
