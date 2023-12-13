#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
pair<int,int> a[N];
int tr[N];
int n;

void modify(int x, int y) {
	for(int i = x; i ; i -= (i&-i)) {
		tr[i] += y;
	}
}
int query(int x) {
	int ans = 0;
	for(int i = x; i<=n; i += (i&-i)) {
		ans += tr[i];
	}
	return ans;
}
int ans = 1;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		modify(a[i].second,1);
		ans=max(ans,query(i+1));
	}
	printf("%d\n",ans);
	return 0;
}


