#include <bits/stdc++.h>
const int N = 1e6+10;
#define int long long

using namespace std;
int n,q;
int a[N];
vector<int> g[N];
int fa[N],siz[N];
int find(int x){
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void merge(int x, int y){
	if(find(x) != find(y)){
		siz[find(x)] += siz[find(y)];
		siz[find(y)] = 0;
		fa[find(y)] = find(x);
	}
}
int sum[N];
map<pair<int,int>, bool> vis;
map<pair<int,int>, vector<pair<int,int> > > e; 
int ffa[N],ssiz[N];
int ffind(int x){
	return ffa[x] == x ? ffa[x] : ffa[x] = ffind(ffa[x]);
}
void mmerge(int x, int y,int &ans){
	if(ffind(x) != ffind(y)){
		ans += 2*ssiz[ffind(x)]*ssiz[ffind(y)];
		ssiz[ffind(x)] += ssiz[ffind(y)];
		ssiz[ffind(y)] = 0;
		ffa[ffind(y)] = ffind(x);
	}
}
signed main(){
//	cin >> n >> q;
	scanf("%lld%lld",&n,&q);
	for(int i = 1;i <= n; i++)scanf("%lld",&a[i]);// cin >> a[i];
	for(int i = 1;i <= n; i++) ffa[i] = i,fa[i] = i,siz[i] = 1;
	for(int i = 2;i <= n; i++){
		int x;
		cin >> x;
		if(a[x] == a[i]){
			merge(x,i);
		}
		g[x].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(siz[i]){
			sum[a[i]] += siz[i]*siz[i];
		}
		for(int j : g[i]){
			int fj = find(j),fi = find(i);
			int mi = min(fi,fj),ma = max(fi,fj);
			if(fj != fi){
				if(!vis.count({mi,ma})){
					vis[{mi,ma}] = 1;
					e[{min(a[i],a[j]),max(a[i],a[j])}].push_back({mi,ma});
				}
			} 
		}
	}
//	cout << endl;
//	for(int i = 1;i <= n; i++) cout << fa[i] << " xxx ";
//	cout << endl;
	for(int i = 1; i <= n; i++) ssiz[i] = siz[i];
	while(q--){
		int x,y;
		cin >> x >> y;
		if(x > y) swap(x,y);
		if(!e.count({x,y})) cout << sum[x] + sum[y] << '\n';
		else{
			int ans = 0;
			for(auto i : e[{x,y}]){
				mmerge(i.first,i.second,ans);
//				cout << i.first << " xxx " << i.second << endl;
			}
//			for(auto i : e[{x,y}]){
//				ans += ssiz[ffind(x)]*ssiz[ffind(x)];
//			}
			cout << ans + sum[x] + sum[y] << '\n';
			for(auto i : e[{x,y}]){
				ffa[i.first] = i.first;
				ffa[i.second] = i.second;
				ssiz[i.first] = siz[i.first];
				ssiz[i.second] = siz[i.second];
			}
		} 
	}
	return 0;
}
