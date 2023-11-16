#include<bits/stdc++.h>
using namespace std;
struct Node{
	int d[6];
} a[1000005];
int n,d,ans;
int main() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= d; j++) {
			cin >> a[i].d[j];
		}
	}
	for(int k = 0; k < (1<<d); k++) {
		int mi = 1e9,ma = -1e9;
		for(int i = 1; i <= n; i++) {
			int sum = 0;
			for(int j = 1; j <= d; j++) {
				if((k>>j-1) &1) sum += a[i].d[j];
				else sum -= a[i].d[j];
			}
			mi = min(mi,sum);
			ma = max(ma,sum);
		}
		ans = max(ans,ma-mi);
	}
	cout << ans;
	return 0;
}

