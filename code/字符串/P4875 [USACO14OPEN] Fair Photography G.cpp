#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
#define ull unsigned long long
const ull BASE = 997;
using namespace std;

#define PII pair<int,int> 
#define ULL unsigned long long 
#define For(i,j,k) for(int i = j; i <= k; i++) 
#define fi first
#define se second

int ans = -1;
int last[10],sum[N][10];
pair<int,int> tmp[10];
unordered_map<ull, int> mp;
ull hs(int s, int i){
	int now = 0;
	while(!(s&(1<<now))&&now<=7) now++;
	ull res = 0;
	for(int j = now+1; j <= 7; j++){
		if(s&(1<<j)) res = res*BASE + sum[i][j] - sum[i][now];
	}
	return res;
}
int n,m;
pair<int,int> a[N];
int xxxx;
signed main(){
	cin >> n >> m;
	m--;
	for(int i = 1;i <= n; i++){
		cin >> a[i].first >> a[i].second;
	 	a[i].second--;
	} 
	sort(a+1,a+1+n);
	for(int i = 1;i <= n; i++){
		for(int j = 0; j <= 7; j++) sum[i][j] = sum[i-1][j];
		sum[i][a[i].second]++;
		for(int j = last[a[i].second]+1; j <= i; j++){
			int s = 0;
			for(int k = 0; k <= 7; k++){
				if(sum[i-1][k] - sum[j-1][k]) s |= (1<<k);
			}
			mp.erase(hs(s,j-1));
			s |= (1<<a[i].second);
			ull h = hs(s,j-1);
			if(!mp.count(h)){
				 mp[h] = a[j].first;
			}
		}
		last[a[i].second] = i;
		for(int j = 0; j <= 7; j++){
			tmp[j] = {last[j],j};
		}
		sort(tmp,tmp+8,greater<pair<int,int> >());
		int s = 0;
		for(int j = 0; j <= m-1; j++) s |= (1<< tmp[j].second);
		for(int j = m; j < 8&&tmp[j].first; j++){
			s |= (1<<tmp[j].second);
			ull h = hs(s,i);
			if(mp.count(h)) ans = max(ans,a[i].first - mp[h]);
		}
	}
	cout << ans;
	return 0;
}
