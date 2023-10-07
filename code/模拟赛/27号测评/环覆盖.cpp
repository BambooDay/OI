#include <bits/stdc++.h>
const int N = 4e5+10;
#define int long long
using namespace std;
struct Node{
	int l, r;
	int id;
}sd[N];
int n, m;
bool cmp(Node x, Node y){
	return x.l < y.l;
}
int ne[N][20];
void init(){
	for(int i = 1,p = 1; i <= 2*n; i++){
		while(p <= 2*n && sd[p].l <= sd[i].r) p++;
		ne[i][0] = p-1;
	}
	for(int i = 1; i <= 18; i++){
		for(int j = 1; j <= 2*n; j++){
			ne[j][i] = ne[ne[j][i-1]][i-1];
		}
	}
}
int res[N];
void solve(int pos){
	int R = sd[pos].l+m,ans = 1,p = pos;
	for(int i = 18; i >= 0; i--){
		if(ne[p][i] != 0 && sd[ne[p][i]].r < R){
			ans += (1<<i);
			p = ne[p][i];
		}
	}
	res[sd[pos].id] = ans+1;
}
signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> sd[i].l >> sd[i].r;
		sd[i].id = i; 
		if(sd[i].l > sd[i].r) sd[i].r += m;
	}
	sort(sd+1,sd+1+n,cmp);
	for(int i = 1; i <= n; i++){
		sd[i+n].id = sd[i].id;
		sd[i+n].l = sd[i].l+m;
		sd[i+n].r = sd[i].r+m;
	}
	init();
	for(int i = 1; i <= n; i++){
		solve(i);
	}
	for(int i = 1;i <= n; i++){
		cout << res[i] << " "; 
	}
	return 0;
} 
