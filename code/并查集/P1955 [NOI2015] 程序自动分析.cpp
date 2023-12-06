#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n;
int fa[N<<2];
int a[N<<2],tot;
struct ques{
	int op,x,y;
}Node[N];
bool cmp(ques x, ques y){
	return x.op < y.op;
}
int id(int x){
	return lower_bound(a+1,a+1+tot,x)-a; 
}
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void init(){
	tot = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> Node[i].x >> Node[i].y >> Node[i].op;
		a[++tot] = Node[i].x;
		a[++tot] = Node[i].y;
	}
	sort(a+1,a+1+tot);
	tot = unique(a+1,a+1+tot)-a-1;
//	memset(fa,0,sizeof fa);
//	sort(Node+1,Node+1+n,cmp);
	
	for(int i = 0; i <= tot*2; i++) fa[i] = i;
}
bool solve(){
	init();
	for(int i =1;i <= n; i++){
		int op = Node[i].op,x = id(Node[i].x),y = id(Node[i].y);
		if(op == 1){ 
			fa[find(x)] = find(y);
		}
	}
	for(int i =1;i <= n; i++){
		int op = Node[i].op,x = id(Node[i].x),y = id(Node[i].y);
		if(op == 0){ 
			if(find(x) == find(y)) return 0;
		}
	}
	return 1;
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		if(solve()) puts("YES");
		else puts("NO");
	}	
	return 0;
}
