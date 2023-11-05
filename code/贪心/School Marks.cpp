#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

int n,k,p,x,y,cnt,now,sum;
int a[N];

int main() {
	cin >> n >> k >> p >> x >> y;
	cnt=(n+1)/2;
	for(int i = 1; i <= k; i++) {
		cin >> a[i];
		if(a[i] >= y) now++;
	}
	if(now+n-k < cnt) { 
		puts("-1");
		return 0;
	}
	int res = max(0, cnt-now);
	for(int i = k+1; i <= k+res;i++) a[i] = y;
	for(int i = k+res+1;i <= n; i++) a[i]=1;
	for(int i = 1; i <= n; ++ i) sum += a[i];
	if(sum > x) puts("-1");
	else{
		for(int i=k+1; i<=n; ++i) cout << a[i] << " ";
	}
	return 0;
}

