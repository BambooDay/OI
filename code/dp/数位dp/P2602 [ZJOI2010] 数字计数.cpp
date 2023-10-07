#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 20;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
ll l,r;
ll f[N][N][2];
int digit;
int a[N];
ll dfs(bool limit, bool lead0, ll cnt, ll pos){
	if(!pos) return cnt;
	ll &now = f[pos][cnt][digit != 0];
	if(!limit && !lead0 && ~now){
		return now;
	}
	int up = limit ? a[pos]:9;
	ll res = 0;
	for(int i = 0; i <= up; i++){
		int cnt1 = (i==digit)+cnt;
		if(lead0 && digit == 0 && i == 0) cnt1 = 0;
		res += dfs(limit && i == up,lead0&&i==0, cnt1,pos-1);	
	} 
	if(!limit && !lead0) now = res;
	return res;
}

ll ans[N];
void solve(ll x, int op){
	int len = 0;
	while(x){
		a[++len] = x % 10;
		x /= 10;
	}
	for(int i= 0; i <= 9; i++){
		digit = i;
		ans[i] += op*dfs(1,1,0,len);
	}
}
int main(){
	memset(f,-1,sizeof f);
	cin >> l >> r;
	solve(r,1);
	solve(l-1,-1);
	for(int i = 0; i<= 9; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
