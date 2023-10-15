#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,m;
int a[N];
int sum = 0;
int  cnt = 0;
signed main(){
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a+1,a+1+n);
	cin >> m;
	for(int i = 1; i <= m; i++){
		int b;
		cin >> b;
		if(b & 1) cnt++;
	}
	for(int i = n; i; i--){
		if(a[i] & 1) sum -= a[i];
		else if(cnt) sum -= a[i],cnt--;
	}
	cout << sum << endl;
	return 0;
}