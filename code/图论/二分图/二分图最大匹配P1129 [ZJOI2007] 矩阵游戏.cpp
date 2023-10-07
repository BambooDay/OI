#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 300;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[N*N],node[N*N],idx= 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
} 
bool v[N];
int match[N];
bool find(int pos){
	for(int i = h[pos];i;i = ne[i]){
		int to = node[i];
		if(!v[to]){
			v[to] = 1;
			int t = match[to];
			if(!t || find(t)){
				match[to] = pos;
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
	int n;
	cin >> n;
	memset(h,0,sizeof h);
	memset(match,0,sizeof match);
	idx = 0;
	for(int i = 1;i <= n; i++){
		for(int j =1;j <= n; j++){
			int x;
			cin >> x;
			if(x) add(i,j);//这里只加一条边，代表i行和j列存在一个匹配 
		}
	}
	int tot = 0;
	for(int i =1;i <=n; i++){//相当于只遍历了行集合 
		memset(v,0,sizeof v);
		if(find(i)) tot++;
	} 
	if(tot ==n) puts("Yes");
	else puts("No");
	
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
