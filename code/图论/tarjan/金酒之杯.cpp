#include <bits/stdc++.h>
const int N = 5e5+10;
using namespace std;
int n, k;
vector<int> c[N];
vector<pair<int,int> > e[N];
int idx = 1;
int dfn[N],low[N],belong[N];
stack<int> st;
int cnt;
int scc = 0;
void tarjan(int pos, int fa){
	dfn[pos] = low[pos] = ++cnt;
	st.push(pos);
	for(auto i : e[pos]){
		if(i.second == (fa^1)) continue;
		int to = i.first;
		if(!dfn[to]){
			tarjan(to,i.second);
			low[pos] = min(low[pos],low[to]);
		}else{
			low[pos] = min(low[pos],dfn[to]); 
		}
	}
	if(low[pos] == dfn[pos]){
		scc++;
		while(st.top() != pos){
			int t = st.top();
			belong[t] = scc;
			st.pop();
		}
		st.pop();
		belong[pos] = scc;
	}
}
int father[N];
int get(int x){
	return x == father[x] ? x : father[x] = get(father[x]);
}
vector<int> g[N];
struct edge{
	int u, v;
}ed[N * 2]; // ×¢Òâ´óÐ¡ 
int m = 0;
int sum = 0;
void dfs(int pos, int fa){
	if(fa == 0 && g[pos].size() == 1) sum++;
	else if(g[pos].size() == 1) sum++;
	for(int to : g[pos]){
		if(to == fa) continue;
		dfs(to,pos);
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1;i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back({v,++idx});
		e[v].push_back({u,++idx});
		ed[++m] = {u,v};
	}	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(c[x].size()){
			ed[++m] = {c[x][c[x].size()-1],i};
			e[c[x][c[x].size()-1]].push_back({i,++idx});
			e[i].push_back({c[x][c[x].size()-1],++idx});
		}
		c[x].push_back(i);
	}
	for(int i = 1;i <= k; i++){
		if(c[i].size() >1){
			ed[++m] = {c[i][c[i].size()-1],c[i][0]};
			e[c[i][0]].push_back({c[i][c[i].size()-1],++idx});
			e[c[i][c[i].size()-1]].push_back({c[i][0],++idx});
		}
	}
	tarjan(1,0);
//	cout<< scc << endl;
	if(scc == 1){
		cout << 0 << endl;
		return 0;
	} 
	for(int i = 1;i <= scc; i++) father[i] = i;
	for(int i = 1;i <= m; i++){
		int u = ed[i].u,v = ed[i].v;
		if(get(belong[u]) != get(belong[v])){
			father[get(belong[u])] = get(belong[v]);
			g[belong[u]].push_back(belong[v]);
			g[belong[v]].push_back(belong[u]);
//			cout << u << " " << v<< endl;
//	cout << 111 <<endl;	
		}
	}
	dfs(1,0);
	cout << (sum +1) / 2;
	return 0;
}
/*
5 4
1 2
2 3
3 4
3 5
1
2
1
3
4
*/ 
/*
5 4
1 2
2 3
3 4
4 5
1 2 3 4 1
*/
/*
4 4
1 2
1 3
1 4
1 2 3 4
*/
