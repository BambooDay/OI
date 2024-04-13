#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
int n,a[N],now,op;
void solve(){
	cin >> n;
	cin >> a[1];
	op = 1;
	now = 1;
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		if(a[i] > a[now]) now = i;
	}
//	int mi = now;
//	for(int i = now + 1;i <= n; i++){
//		if(a[i] < a[mi]) mi = i;
//		if(mi != i)
//	}
	bool flag = (a[1] > a[n]);
	if(flag) puts("NO");
	else puts("YES");
	return;
}
int main(){
	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
