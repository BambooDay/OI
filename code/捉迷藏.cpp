#include <bits/stdc++.h>
#define ll long long
const int N = 2e4+10;
const int M = 5e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int head[N],ne[M],node[M],idx = 0;
void add(int u, int v){
	ne[++idx] = head[u];
	node[idx] = v;
	head[u] = idx;
}
int n, m;
int dis[N];
bool v[N];
priority_queue<pair<int,int>> q;
int ma = INF;
void dij(){
	dis[1] = 0;
	q.push(make_pair(dis[1],1));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(v[u]) continue;
		ma = min(ma,dis[u]);
		v[u] = 1;
		//cout << u << " :"<< endl;
		for(int i = head[u]; i != -1; i = ne[i]){
			int t = node[i];
			//cout << t << " ";
			if(!v[t] && (dis[t] < dis[u] - 1|| dis[t] == INF)){
				dis[t] = dis[u] -1;
				q.push(make_pair(dis[t],t));
				//cout << t << " "<< dis[t] << endl;
			}
		}
		//cout << endl;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	memset(head,-1,sizeof head);
	memset(dis,0x3f,sizeof dis);
	for(int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dij();
	int id = 0,sum = 0;
	for(int i = 1; i <= n; i++){
		//cout << dis[i] << " ";
		if(dis[i] == ma){
			sum++;
			if(!id){
				id = i;
			}
		}
	}
	//cout << endl;
	printf("%d %d %d",id,-ma,sum);
	//cout << id << " "<< -ma << " "<< sum;
	return 0;
}

