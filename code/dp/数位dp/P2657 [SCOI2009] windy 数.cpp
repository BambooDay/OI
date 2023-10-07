#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 20;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
ll l,r;
ll f[N][N];
int digit;
int a[N];
ll dfs(bool limit, bool lead0, int last, ll pos){
	if(!pos) return 1;
	ll &now = f[pos][last];
	if(!limit && !lead0 && last != INF && ~now){
		return now;
	}
	int up = limit? a[pos]:9;
	ll res =0 ;
	for(int i = 0;i <= up; i++){
		if(lead0){
			res += dfs(i == up&& limit, lead0 && i == 0 , i == 0 ? INF : i, pos-1);
		}else{
			if(abs(last - i) >= 2){
				res += dfs(i == up && limit,lead0&&i==0,i,pos-1);
			}
		}
		
	}
	if(!limit && !lead0 && last != INF){
		now = res;
	}
	return res;
}

ll ans[N];
ll solve(ll x){
	int len = 0;
	while(x){
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(1,1,INF,len);
}
int main(){
	memset(f,-1,sizeof f);
	cin >> l >> r;
	cout << solve(r) - solve(l-1);
	return 0;
}
