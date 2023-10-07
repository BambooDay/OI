#include <bits/stdc++.h>
const int N = 9000;
#define int long long
const int mod = 1e9+7;

using namespace std;
int n,a[N];
int k, nxt[N],ans;
struct cmp{
	bool operator()(pair<int,int> p, pair<int,int> q){
		return 1.*a[p.first] / a[q.second] < 1.*a[q.first]/a[p.second];
	}
};
priority_queue<pair<int,int> , vector<pair<int,int> > ,cmp> q;

int len,d[20],cnt = 0;
int t[N];
map<int,int> m;
bool vis[20][N];
void init(int w, int now, bool ava){
	if(!~w){
		if(!m.count(now)) m[t[cnt] = now] = cnt,cnt++;
		return;
	}
	if(vis[w][m[now]]) return;
	vis[w][m[now]] = 1;
	int up = ava ? 9 : d[w];
	for(int i = 1; i <= up; i++) init(w-1,now*i,ava|| i < up);
}
void INIT(){
	while(n){
		d[len++] = n % 10;
		n /= 10;
	}
	for(int i = 0; i <= len; i++){
		init(i-1,1,i < len);
	}
}
int f[20][N];
int dp(int w, int now, int ava){
	if(!~w) return now == 0;
	if(ava && ~f[w][now]) return f[w][now];
	int up = ava ? 9 : d[w];
	int res = 0;
	for(int i = 1; i <= up; i++){
		if(t[now] % i == 0){
			res += dp(w-1,m[t[now] / i], ava || i < up);
		}
	}
	if(ava) f[w][now] = res;
	return res;
}
void DP(){
	memset(f,-1,sizeof f);
	for(int i = 0; i < cnt; i++){
		for(int j = 1; j <= len; j++){
			a[i] += dp(j-1,i,j < len); 
		}
	}
}
signed main(){
	cin >> n >> k;
	INIT();
	DP();
	sort(a,a+cnt,[](int x, int y){return x > y;});
	for(int i = 0; i < cnt; i++){
		nxt[i] = 0;
		q.push(make_pair(i,nxt[i]++));
	}
	while(k-- && !q.empty()){
		pair<int, int> u = q.top();
		q.pop();
		ans = (ans + (a[u.first] % mod)*(a[u.second] % mod) % mod ) % mod;
		if(nxt[u.first] < cnt) u.second = nxt[u.first]++,q.push(u);
	}
	cout << ans;
	return 0;
}
