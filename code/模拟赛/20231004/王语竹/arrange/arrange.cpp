#include <bits/stdc++.h>
const int N = 5e5+10;
#define int long long
using namespace std;
int n;
int node[N<<2];
#define ls(fa) fa << 1
#define rs(fa) fa << 1|1
void push_up(int pos){
	node[pos] = min(node[ls(pos)],node[rs(pos)]);	
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = n+1;
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void modify(int pos, int l, int r, int x, int y){
	if(l == r){
		node[pos] = y;
		return;
	}
	int mid = (l+r) >> 1;
	if(x <= mid){
		modify(ls(pos),l,mid,x,y);	
	}else{
		modify(rs(pos),mid+1,r,x,y);
	}
	push_up(pos);
}
int query(int pos, int l, int r, int x, int y){
//cout << l << " " << r  << " " << x << " " << y<< endl;
	if(x > y) return n+1;
	if(x <= l && r <= y){
		return node[pos];
	}
	int ans = 1e18;
	int mid = (l+r) >> 1;
	if(x <= mid){
		ans = min(ans,query(ls(pos),l,mid,x,y));
	}
	if(mid < y){
		ans = min(ans, query(rs(pos),mid+1,r,x,y));
	}
	return ans;
}


int pos[N],a[N];
int m;
int dp[N][2],ans = 1e18;
int pos1[N],pos2[N],ne[N][2];

int ask(int x){
//	cout << x << endl;
	int mi = n+1;
	if (x+m-1<=n-1){
		mi = min(mi,query(1,1,n,0+1,x-1+1));
		mi = min(mi,query(1,1,n,x+m+1,n-1+1));
	}else{
		mi = min(mi ,query(1,1,n,x+m-n+1,x-1+1));
	} 
	return mi;
}
signed main() {
	freopen("arrange.in","r",stdin);
	freopen("arrange.out","w",stdout);
	cin >> n >> m;
	if(n == m){
		cout << 0;
		return 0;
	}
	for(int i = 1; i<=n; i++) {
		cin >> a[i];
		pos[a[i]] = i-1;
		dp[i][0] = dp[i][1] = 1e18;
	}
	dp[0][0] = 1e18,dp[0][1] = 0;
	build(1,1,n);
	for(int i = n; i >= 0; i--){
		pos1[i] = (pos[i]+n-m+1)%n;
		ne[i][0] = ask(pos1[i]);
		pos2[i] = pos[i];
		ne[i][1] = ask(pos2[i]);
		modify(1,1,n,pos[i]+1,i);
	}
//	return 0;
	for(int i = 0;i <= n; i++){
		if(ne[i][0] == n+1) ans = min(ans,dp[i][0]);
		else{
			dp[ne[i][0]][0] = min(dp[ne[i][0]][0],dp[i][0] + (pos1[ne[i][0]] - pos1[i]+n) % n);
			dp[ne[i][0]][1] = min(dp[ne[i][0]][1],dp[i][0] + (pos1[i] - pos2[ne[i][0]]+n) % n);
		}
		if(ne[i][1] == n+1) ans = min(ans,dp[i][1]);
		else{
			dp[ne[i][1]][0] = min(dp[ne[i][1]][0],dp[i][1] + (pos1[ne[i][1]] - pos2[i]+n) % n);
			dp[ne[i][1]][1] = min(dp[ne[i][1]][1],dp[i][1] + (pos2[i] - pos2[ne[i][1]]+n) % n);			
		}
	}
	cout << ans << endl;
	return 0;
}

/*
dp[i][0/1] 表示当前到了数字 i ，0 ：i 位于 1 号位置， 1： i 位于 m 号位置

*/

