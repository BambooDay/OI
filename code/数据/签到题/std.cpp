#include <bits/stdc++.h>
const int N = 2e6+10;

using namespace std;
int fa[N],siz[N];
int n,t;
struct Node{
	vector<int> v;
	int k;
	int id;
}a[N];
bool cmp(Node x, Node y){
	return x.k < y.k;
}
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int vis[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i].k);
		a[i].id = i;
		a[i].v.clear();
		for(int j = 1;j <= a[i].k; j++){
			int x;
			scanf("%d",&x);
			a[i].v.push_back(x+1000000);
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n; i++){
		fa[i] = i;
		siz[i] = 0;
	}
	for(int i = 1000000+1; i <= n+1000000; i++){
		fa[i] = i;
		siz[i] = 1;
	}
	int ansa=0,ansb=0;
	for(int i = 1;i <= n; i++){
		for(int j : a[i].v){
			int fj = find(j),fi = find(i);
			if(fj != fi){
				siz[fj] += siz[fi];
				fa[fi] = fj;
			}
		}
		int fi = find(i);
		if(siz[fi] > a[i].k){
			ansa = i;
			break;
		}
	}
	if(ansa){
		puts("YES");
	}else{
		puts("NO");
	}
}
int main(){
//	freopen("sign.in","r",stdin);
//	freopen("sign.out","w",stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}
