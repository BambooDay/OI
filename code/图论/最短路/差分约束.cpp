#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int h[N],node[N],ne[N],val[N];
int idx;
void add(int u, int v, int w){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
	val[idx] = w;
}
int n, m;
int dis[N];
int cnt[N];
bool in[N];
bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	queue <int> q;
	for(int i = 1;i <= n; i++){
		q.push(i);
		in[i] = 1;
		cnt[i]++;
	}
	while(!q.empty()){
		int u = q.front();
//		cout << u << " " << cnt[u] << endl;
		q.pop();
		in[u] = 0;
		for(int i = h[u]; i ; i = ne[i]){
			int t = node[i];
			if(dis[t] > dis[u] + val[i]){
				dis[t] = dis[u] + val[i];
				if(!in[t]){
					q.push(t);
					in[t] = 1;
					cnt[t]++;
					if(cnt[t] > n+1){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main(){
//	freopen("P5960_1.in","r",stdin);
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		add(y,x,z);
	}
	if(spfa()) cout << "NO";
	else{
		for(int i = 1; i <= n; i++){
			cout << dis[i] << " ";
		}
	}
	return 0;
}
