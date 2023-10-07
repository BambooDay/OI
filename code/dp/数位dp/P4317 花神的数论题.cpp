#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e7+7;

using namespace std;
int a[60];
ll n;
ll f[60][60];
ll dfs(int pos,int cnt, bool limit){
	if(!pos) return max(cnt,1);
	ll &now = f[pos][cnt];
	if(~now && !limit) return now;
	int up = limit? a[pos]:1;
	ll res = 1;
	for(int i = 0;i <= up; i++){
		res = res * dfs(pos-1,cnt+(i == 1),limit && (i == up))%mod;
	}
	if(!limit) now = res;
	return res;
}
int main(){
	cin >> n;
	memset(f,-1,sizeof f);
	int len = 0;
	while(n){
		a[++len] = n % 2;
		n /= 2;
	}
	cout << dfs(len,0,1);
	
	return 0;
}
