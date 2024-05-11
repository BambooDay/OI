#include <bits/stdc++.h>
const int N = 7.5e6+10;
#define int long long

using namespace std;
int n,t,r;
int x[N];
//int L[N][25],R[N][25];

signed main(){
	freopen("lighthouse.in","r",stdin);
	freopen("lighthouse.out","w",stdout);
	cin >> n >> t >> r;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(!t) puts("0"),exit(0);
	int st = 1,nw = 0;
	t--;
	for(int i = 1; i <= n; i++){
		if(x[i]-x[st] <= r) continue;
		else{
			if(!nw) nw = i-1;
			if(x[i]-x[nw] <= r) continue;
			st = i;
			t--;
			if(t < 0){
				cout << i-1 << endl;
				return 0;
			}
		}
	} 
	cout << n << "\n";
	return 0; 
}
