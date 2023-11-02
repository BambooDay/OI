#include <bits/stdc++.h>
const int N = 3e5+10;

using namespace std;
int n,m;
vector<pair<int,int> > e[N];
int dis[N];
bool in[N];
int a[N];
void add(int u,int v,int w){
	e[u].push_back(make_pair(v,w));
}
void spfa(){
	memset(dis,128,sizeof dis);
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	in[1] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = 0;
		for(auto v : e[u]){
			int to = v.first,w = v.second;
//			cout << u << " " << to << " " << w << endl;
			if(dis[to] < dis[u]+w){
				dis[to] = dis[u]+w;
				if(!in[to]){
					q.push(to);
					in[to] = 1;
				}
			}
		} 
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		add(i,i+n,-a[i]);
		add(i+n,i+n+n,a[i]);
	}	
	for(int i = 1;i <= m; i++){
		int u,v,op;
		cin >> u >> v >> op;
		if(op == 1){
			for(int j = 0; j < 3; j++){
				add(u+j*n,v+j*n,0);
			}
		}else{
			for(int j = 0; j < 3; j++){
				add(u+j*n,v+j*n,0);
				add(v+j*n,u+j*n,0);
			}			
		}
	}
	spfa();
//	cout << dis[n*3] << endl;
	cout << max(dis[n],dis[n*3]) << endl;
	return 0; 
}
