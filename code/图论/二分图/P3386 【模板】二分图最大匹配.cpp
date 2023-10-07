#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1020;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m, e;

int h[N],ne[M],node[M],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int match[N],v[N];
bool find(int pos){
	for(int i = h[pos];i;i=ne[i]){
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
int main(){
	cin >> n >> m;
	cin >> e;
	for(int i =1;i <= e; i++){
		int x, y;
		cin >> x >> y;
		add(x,y+500);
		add(y+500,x);
	}
	int ans = 0;
	for(int i = 1; i<= n; i++){
		memset(v,0,sizeof v);
		if(find(i)) ans++; 
	}
	cout << ans;
	return 0;
}
