#include <bits/stdc++.h>
#define int long long
const int N = 5e5+10;

using namespace std;
int l[N],r[N],x[N];
int n,X;
int L,R,last;
bool flag;

void get_ans() {
	for(int i = 1; i <= n; i++) {
		R = R+(x[i]-last);
		L = max(L,l[i]);
		R = min(R,r[i]);
		if(L > R) {
			puts("NIE");
			flag = 1;
			exit(0);
		}
		last = x[i];
	}
}
signed main() {
	cin >> n >> X;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> l[i] >> r[i];
		if(l[i]+x[i] == -1) l[i] = 0;
		else l[i] = (x[i]+l[i])/2+1;
		if(r[i]-1+x[i] == -1)	r[i] = -1;
		else r[i] = (r[i]-1+x[i])/2;
		if(l[i] > r[i] && !flag) {
			//printf("NIE\n");
			flag = true;
		}
	}
	if(flag) {
		puts("NIE");
		return 0;
	}
	get_ans();
	if(!flag) cout << L;
	return 0;
}
