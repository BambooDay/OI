#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int h[N],ne[M],node[M],val[M];
int idx;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u]; 
	h[u] = idx;
	val[idx] = w;
}
int dis[N],cnt[N];
bool in[N];
bool spfa(int n, int s){
	for(int i = 0; i <= n; i++){
		dis[i] = INF,cnt[i] = 0,in[i] = 0;
	}
	dis[s] = 0;
	queue<int> q;
	for(int i = 1; i <= n; i++){
		q.push(i);
		cnt[i]++;
		in[i] = 1;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = 0;
		for(int i = h[u]; i; i = ne[i]){
			int t = node[i];
			if(dis[t] > dis[u] + val[i]){
				dis[t] = dis[u] + val[i];
				if(!in[t]){
					q.push(t);
					in[t] = 1;
					if(++cnt[t] > n+1){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
void solve(){
	int n, m;
	cin >> n >> m;
	memset(h,0,sizeof(h));
	memset(ne,0,sizeof(ne));
	memset(node,0,sizeof(node));
	memset(val,0,sizeof(val));
	idx = 0;
	while(m--){
		int s,t,v;
		cin >> s >> t >> v;
		add(s-1,t,v);
		add(t,s-1,-v);
	}
	if(spfa(n,1)) cout << "false" << endl;
	else cout << "true" << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
