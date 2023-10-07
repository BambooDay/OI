#include<bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
int n,m;
long long a[N],tree[N],c[N],sum[N][60];
void modify(int x, int y) {
	for(int i = x; i <= 50; i += (i& -i)) {
		tree[i] += y;
	}
}
long long ask(int x) {
	long long ans = 0;
	for(int i = x; i; i -= (i&-i)) {
		ans += tree[i];
	}
	return ans;
}

int main() {
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		for(int j=1; j<=50; j++) {
			sum[i][j]=((j==a[i])+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]);
		}
	}
	for(int i=1; i<=n; i++) {
		modify(a[i],1);
		c[i]=c[i-1]+i-1-ask(a[i]-1)-(sum[i][a[i]]-sum[i][a[i]-1]-1);
	}
	while(m--) {
		int l,r;
		scanf("%d%d",&l,&r);
		long long ans=0;
		ans=c[r]-c[l-1];
		for(int i=1; i<=50; i++) {
			ans-=(sum[l-1][i]-sum[l-1][i-1])*(sum[r][i-1]-sum[l-1][i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

