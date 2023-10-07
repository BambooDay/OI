#include <bits/stdc++.h>

using namespace std;
int n, m;
int h[200],ne[1000002],node[1000006],idx = 1;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int dfn[300],low[300],cnt;
vector<pair<int,int> > ans;
void tarjan(int pos,int e, int fa){
	dfn[pos] = ++cnt;
	low[pos] = dfn[pos];
	for(int i = h[pos];i;i = ne[i]){
		if(i == (e^1)) continue;
		int to = node[i];
		if(!dfn[to]){
			tarjan(to,i,pos);
			low[pos] = min(low[pos],low[to]);
		}else{
			low[pos] = min(low[pos],dfn[to]);
		}
	}
	if(low[pos] == dfn[pos]){
		if(fa == 0) return;
		if(fa < pos){
			ans.push_back(make_pair(fa,pos));
		}else{
			ans.push_back(make_pair(pos,fa));
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i<= m; i++){
		int x, y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	tarjan(1,0,0);
	sort(ans.begin(),ans.end());
	for(auto i : ans){
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}
