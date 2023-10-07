#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> e[10005];
int d[10005];
bool flag;
int mid;
int dfs(int x, int fa){
	multiset<int> s;
	for(int i : e[x]){
		if(i == fa) continue;
		s.insert(dfs(i,x));
	}
	int num = 0,cnt = 0;
	while(!s.empty()){
		auto it = s.end();
		it--;
		int k = *it;
		s.erase(it);
		if(k > mid) flag = 0;
		auto to = s.upper_bound(mid - k);
		if(to == s.begin()){
			if(cnt > 1){
				flag = 0;
			}else{
				num = k;
				cnt++;
			}
		}else{
			to--;
			s.erase(to);
		}
	} 
	if(d[x] % 2 && cnt > 1) flag = 0;
	if(x == 1 && d[x] % 2 == 0 && cnt) flag = 0;
	return num+1;
}                        
signed main(){
	cin >> n;
	int ans = n-1;
	for(int i = 1;i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	for(int i = 1; i <= n; i++){
		ans -= d[i]/2;
	}
	cout << ans << " ";
	for(int i = 2; i <= n; i++) d[i]--;
	int l = 1,r = n-1;
	while(l <= r){
		mid = (l+r) >> 1;
		flag = 1;
		if(dfs(1,1) > mid+1) flag = 0;
		if(!flag){
			l = mid+1;
		}else{
			ans = mid;
			r = mid-1;
		}
	}
	cout << ans << endl;
	return 0;
}
