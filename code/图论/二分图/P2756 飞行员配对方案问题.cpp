#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[300],ne[M],node[M],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

int match[300];
bool v[300];
bool find(int pos){
	for(int i = h[pos]; i; i = ne[i]){
		int to = node[i];
		if(v[to]) continue;
		v[to] = 1;
		int t = match[to];
		if(!t || find(t)){
			match[to] = pos;
			match[pos] = to;
			return 1;	
		}
	}
	return 0;
} 
int n, m;

int main(){
	cin >> m >> n;
	int x, y;
	cin >> x>> y;
	while(x != -1 && y != -1){
		add(x,y);
		add(y,x);
		cin >> x >> y;
	}
	int tot = 0;
	for(int i = 1; i <= m; i++){
		memset(v,0,sizeof v);
		if(find(i)){
			tot++;
		}
	}
	cout << tot << endl;
	for(int i =1;i <= m; i++){
		if(match[i]){
			cout << i << " " << match[i] << endl;
		}
	}
	return 0;
}
