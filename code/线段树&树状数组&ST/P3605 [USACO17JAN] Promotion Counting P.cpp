#include<bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int a[N],tot,b[N];
int n;
vector<int> e[N];
int get(int x){
	return lower_bound(b+1,b+1+tot,x)-b-1;
}
int tr[N];
void modify(int x,int y){
	for(int i = x; i; i -= (i&-i)) tr[i] += y;
}
int query(int x){
	int res = 0;
	for(int i = res;i <= n; i += (i&-i)) res += tr[i];
	return res;
}
int ans[N];
void dfs(int pos, int fa){
	modify(get(a[pos]),1);
	int cnt = query(get(a[pos]));
	for(int to : e[pos]){
		if(to == fa) continue;
		dfs(to,pos);
	}
	ans[pos] = query(get(a[pos]))-cnt;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		b[++tot] = a[i];
	}
	sort(b+1,b+1+tot);
	tot = unique(b+1,b+1+tot)-b-1;
	for(int i =2 ;i <= n; i++){
		int fa;
		cin >> fa;
		e[fa].push_back(i);
	}	
	dfs(1,0);
	for(int i = 1;i <= n; i++) cout << ans[i] << endl;
	return 0;
}
