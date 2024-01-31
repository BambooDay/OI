#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int sum[N];
int n,q;
char s[N];
void solve(){
//	cin >> n >> q;
	scanf("%d%d",&n,&q);
	sum[0] = 0;
//	cin >> s;
	scanf("%s",s+1); 
//	s = " " + s;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + s[i]-'0';
	}
	while(q--){
		int l,r;
//		cin >> l >> r;
		scanf("%d%d",&l,&r);
		if(s[l] == '1'&&(sum[l-1] - sum[0])){
			puts("Yes");
			continue;
		}
		if(s[l] == '0' && (sum[l-1]-sum[0] < l-1)){
			puts("Yes");
			continue;
		}
		if(s[r] == '1' && (sum[n]-sum[r])){
			puts("Yes");
			continue;
		}
		if(s[r] == '0' && (sum[n]-sum[r] < n-r)){
			puts("Yes");
			continue;
		}
		puts("No");
	}
}
int main(){
//	freopen("sub2.in","r",stdin);
//	freopen("sub2.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
