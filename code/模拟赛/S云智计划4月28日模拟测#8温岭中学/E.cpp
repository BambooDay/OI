#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e6+10;
const ull BASE = 13331;
using namespace std;
map<ull,int> mp;
ull hs[N],base[N];
string s;
int n;

int dfs(int fi,int md,int len){
	if(!len || md > n) return 0;
//	cout << fi << " " << md << endl;
	ull cd = s[fi]*base[n-md+1]+hs[n]-hs[md-1]*base[n-md+1];
	if(mp[cd]) return 0;
//	cout << cd << " " <<  len << endl;
	int cnt = 0;
	cnt += dfs(fi,md+1,len-1)+dfs(md,md+1,len-1);
	mp[cd] = cnt+1;
	return cnt+1;
}
bool ask(int fi, int md){
	ull cd = s[fi]*base[n-md+1]+hs[n]-hs[md-1]*base[n-md+1];
	if(mp[cd]) return 0;
	mp[cd] = 1;
	return 1;	
}
bool v[150];
map<pair<int,int> ,int> ans;
void solve(){
	cin >> n >> s;
	if(n == 1){
		puts("1");
		return;
	}
	mp.clear();
	ans.clear();
	memset(v,0,sizeof v);
	base[0] = 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		hs[i] = hs[i-1]*BASE+s[i-1];
		base[i] = base[i-1]*BASE;
		if(!v[s[i-1]]) cnt++;
		v[s[i-1]] = 1;
	}
	queue<pair<int,int> > q;
	q.push({1,2});
	while(!q.empty()){
		pair<int,int> t = q.front();
		cnt++;
		q.pop();
		if(t.second == n) continue;
		if(ask(t.first,t.second+1)) q.push({t.first,t.second+1});
		if(ask(t.first+1,t.second+1)) q.push({t.first+1,t.second+1});
	}
	cout << cnt << "\n";
	return ;
}
signed main(){
//	freopen("2.in","r",stdin);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
