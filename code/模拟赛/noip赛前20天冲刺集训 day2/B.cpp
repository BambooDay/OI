#include <bits/stdc++.h>
#define int long long
const int N = 3e5+10;
using namespace std;

int n,m;
int vis[N];
int now;
vector<pair<int,int> >v[N];
bool check(int mid){
	vector<int> id[2];
	fill(vis+1,vis+1+n,0);
	vis[1]=1;
	id[now].push_back(1);
	for(int i=1;i<n;i++){
		now ^= 1;
		id[now].clear();
		for(int x:id[now^1])
			for(auto p:v[x]){
				int y=p.first;
				if(!vis[y]&& i*p.second<=mid) vis[y]=1,id[now].push_back(y);
			}
	}
	return vis[n];
}
signed main(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int u,vv,w;
		//cin >> u >> vv >> w;
		scanf("%lld%lld%lld",&u,&vv,&w);
		v[u].push_back({vv,w});
	}
	int l=1,r=3e14,ans=0;
	while(l<=r){
		int  mid=(l+r) >> 1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout << ans << endl;
	return 0;
}