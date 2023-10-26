#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n, m, tot, b[N],fa[N];
struct Node{
	int u,v;
	string op;
}a[N];
int find(int x){
	return  fa[x] == x ? x : fa[x] = find(fa[x]);

}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].op;
		b[++tot] = a[i].u;
		b[++tot] = a[i].v;
	}	
	sort(b+1,b+1+tot);
	tot = unique(b+1,b+1+tot)-b-1;
	for(int i = 1;i <= m; i++){
		a[i].u = lower_bound(b+1,b+1+tot,a[i].u-1)-b;
		a[i].v = lower_bound(b+1,b+1+tot,a[i].v)-b;
	}
	for(int i =1; i <= tot*2; i++) fa[i] = i;
	for(int i =1;i <= m; i++){
		if(a[i].op == "even"){
			if(find(a[i].u)==find(a[i].v+tot)||find(a[i].u+tot)==find(a[i].v)) {
				cout << i-1; 
				return 0;
			}
			fa[find(a[i].u)]=find(a[i].v);
			fa[find(a[i].u+tot)]=find(a[i].v+tot);			
		}else{
			if(find(a[i].u)==find(a[i].v)||find(a[i].u+tot)==find(a[i].v+tot)) {
				cout << i-1;
				return 0;
			}
			fa[find(a[i].u)]=find(a[i].v+tot);
			fa[find(a[i].u+tot)]=find(a[i].v);			
		}
	}
	cout << m << endl;
	return 0;
}
