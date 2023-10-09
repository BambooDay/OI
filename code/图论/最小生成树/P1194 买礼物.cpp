#include <bits/stdc++.h>
const int N = 600;

using namespace std;
int a,n;
struct Node{
	int u,v,w;
}e[N*N];
int cnt = 0;
bool cmp(Node a, Node b){
	return a.w < b.w;
}
int fa[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int ans = 0,tot = 0;
int main(){
	freopen("123.in","r",stdin);
	freopen("123.out","w",stdout);
	cin >> a >> n;
	for(int i = 1; i <= n; i++) e[++cnt] = {i,n+1,a};
	for(int i = 1;i <= n+1; i++) fa[i] = i;
	for(int i = 1;i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(x) e[++cnt] = {i,j,x};
		} 
	} 
	sort(e+1,e+1+cnt,cmp);
	for(int i =1;i <= cnt; i++){
		int fu = find(e[i].u),fv = find(e[i].v);
		if(fu != fv){
			//cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
			fa[fu] = fv;
			tot++;
			ans += e[i].w;
		}
		if(tot == n) break;
	}
	cout << ans << endl;
	return 0;
}