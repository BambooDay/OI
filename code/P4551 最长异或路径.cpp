#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int h[N],ne[N*2],w[N*2],node[N*2],idx = 0;

void add(int u, int v,int z){
	ne[++idx] = h[u];
	node[idx] = v;
	w[idx] = z;
	h[u] = idx;
}
int trie[N*32][5],tot = 0;
void build(int num){
	int p = 0;
	for(int i = 31; i >=0; i--){
		int k = (num >> i) & 1;
		if(!trie[p][k]) trie[p][k] = ++tot;
		p = trie[p][k];
	}
}
int d[N];
bool v[N];
void init(int pos){
	for(int i = h[pos];i;i = ne[i]){
		int to = node[i];
		if(v[to]) continue;
		v[to] = 1;
		d[to] = w[i] ^ d[pos];
		init(to);
	}
}
void dfs(int x){
	for(int i=h[x];i;i=ne[i]){
		int y=node[i],z=w[i];
		if(v[y])  continue;
		v[y]=1;
		d[y]=d[x]^z;
		dfs(y);
	}
}
int n;
signed main(){
	cin >> n;
	for(int i = 1;i < n; i++){
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z);
		add(y,x,z);
	}
//	memset(d,0x3f,sizeof d);
//	d[1] = 0;
	v[1] = 1;
	init(1);
	dfs(1);
	int ans = 0;
	for(int i = 1;i <= n; i++){
		build(d[i]);
	
		if(i == 1) continue;
		int p = 0 ,cnt = 0;
		for(int j = 31; j >= 0; j--){
			int k = (d[i] >> j) & 1;
			if(trie[p][k^1]){
				cnt = (cnt << 1) + (k ^ 1);
				p = trie[p][k ^ 1];
			}else if(trie[p][k]){
				cnt = (cnt << 1) + k;
				p = trie[p][k];
			}
		}
		ans = max(ans,cnt ^ d[i]);

	}
	cout << ans;
	return 0;
}
