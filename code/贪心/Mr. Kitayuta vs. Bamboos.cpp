#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
int n, m, k, c[N];
long long p,a[N],h[N];
bool check(long long x){
	memset(c,0,sizeof c);
	priority_queue<pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> > > q;
	for(int i = 1;i <= n; i++){
		if(x - a[i]*m < h[i]) q.push(make_pair(x/a[i],i));
	}
	for(int i = 1; !q.empty() && i <= m; i++){
		for(int j = 1; !q.empty() && j <= k; j++){
			pair<int,int> u = q.top();
			q.pop();
			if(u.first < i) return 0;
			c[u.second]++;
			if(x + c[u.second]*p - a[u.second]*m < h[u.second]){
				q.push(make_pair((x+c[u.second]*p)/a[u.second],u.second));
			}
		}
	}
	return q.empty();
}
int main(){
	cin >> n >> m >> k >> p;
	for(int i = 1;i <= n; i++) cin >> h[i] >> a[i];
	long long l = 0,r = 1e13,ans;
	while(l <= r){
		long long mid = (l+r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}	
	cout << ans;
	return 0;
}
