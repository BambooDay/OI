#include <bits/stdc++.h>
#define int long long

using namespace std;
map<int,int> mp;
int n,m;
int k[10],p[10];
int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans *= a;
		a = a*a;
		b >>= 1;
	}
	return ans;
} 
int ans = 0;
void dfs1(int dep, int sum){
	if(!dep){
		mp[sum]++;
		return;
	}
	for(int i = 1; i <= m; i++){
		dfs1(dep-1,sum + k[dep]*ksm(i,p[dep]));
	}
}
void dfs2(int dep, int sum){
	if(!dep){
		ans += mp[-sum];
		return;
	}
	for(int i = 1; i <= m;i++){
		dfs2(dep-1,sum+k[dep+n/2]*ksm(i,p[dep+n/2]));
	}
}
signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) cin >> k[i] >> p[i];
	dfs1(n/2,0);
	dfs2(n-n/2,0);
	cout << ans << endl; 
	return 0;
} 
