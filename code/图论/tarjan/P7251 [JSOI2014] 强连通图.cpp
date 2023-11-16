#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int belong[N],tot;
int dfn[N],low[N],idx = 0;
vector<int> e[N];
int n,m;
stack<int> st;
int ans = 1;
void tarjan(int pos){
	low[pos] = dfn[pos] = ++idx;
	st.push(pos);
	for(int to : e[pos]){
		if(!dfn[to]){
			tarjan(to);
			low[pos] = min(low[pos],low[to]);
		}else{
			if(!belong[to]) low[pos] = min(low[pos],dfn[to]);
		}
	}
	if(low[pos] == dfn[pos]){
		tot++;
		int cnt = 1;
		while(st.top() != pos){
			belong[st.top()] = tot;
			st.pop();
			cnt++;
		}
		st.pop();
		belong[pos] = tot;
		ans = max(ans,cnt);
	}
}
int in[N],out[N];
struct edge{
	int u,v;
}ed[N*3];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		int u,v;
		cin >> u >> v;
		ed[i] = {u,v};
		e[u].push_back(v);
	}	
	for(int i = 1;i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}	
	for(int i = 1; i <= m; i++){
		if(belong[ed[i].u] != belong[ed[i].v]){
			out[belong[ed[i].u]]++;
			in[belong[ed[i].v]]++;
		}
	}
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1;i <= tot; i++){
		if(!in[i]) cnt1++;
		if(!out[i]) cnt2++;
	}
	if(tot == 1) cnt1 = cnt2 = 0;
	cout << ans << "\n" << max(cnt1,cnt2);
	return 0;
}
