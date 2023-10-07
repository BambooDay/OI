//#include <bits/stdc++.h>
//
//using namespace std;
//int n;
//vector<int> e[200];
//int scc,belong[200];
//stack<int> st;
//int dfn[200],low[200];
//int cnt;
//bool in[200];
//vector<pair<int,int> > point;
//void tarjan(int pos,int fa){
//	dfn[pos] = ++cnt;
//	low[pos] = dfn[pos];
//	st.push(pos);
//	in[pos] = 1;
//	for(auto to : e[pos]){
//		if(!dfn[to]){
//			tarjan(to,pos);
//			low[pos] = min(low[pos],low[to]);
//		}else{
//			if(in[to]){
//				low[pos] = min(low[pos],dfn[to]);
//			}
//		}
//	}
//	if(low[pos] == dfn[pos]){
//		if(fa){
//			point.push_back(make_pair(fa,pos));
//		}
//		belong[pos] = ++scc;
//		while(st.top() != pos){
//			belong[st.top()] = scc;
//			in[st.top()] = 0;
//			st.pop();
//		}
//		in[pos] = 0;
//		st.pop();
//	}
//}
//int in[200],out[200];
//int main(){
//	cin >> n;
//	for(int i = 1; i<= n; i++){
//		int x;
//		while(cin >> x && x){
//			e[i].push_back(x);
//		}
//	}
//	for(int i = 1;i <= n; i++){
//		if(!belong[i]){
//			tarjan(i,0);
//		}
//	}
//
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
int n;
int cnt, top, col;
vector<int>G[N];
int dfn[N], low[N], st[N], color[N], col_s[N];
int rd[N], cd[N];
void Tarjan(int u) { 
	dfn[u] = low[u] = ++cnt;
	st[++top] = u;
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (!color[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		color[u] = ++col;
		while (st[top] != u) {
			color[st[top]] = col;
			top--;
		}
		top--;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (x != 0) {
			G[i].push_back(x);
			cin >> x;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])Tarjan(i);
	for (int u = 1; u <= n; u++) {
		for (int j = 0; j < G[u].size(); j++) {
			int v = G[u][j];
			if (color[u] != color[v])
				rd[color[v]]++, cd[color[u]]++;
		}
	}
	int Aans = 0, Bans = 0;
	for (int i = 1; i <= col; i++) {
		if (rd[i] == 0)Aans++;
		if (cd[i] == 0)Bans++;
	}
	cout << Aans << endl;
	if (col == 1)cout << 0;
	else cout << max(Aans, Bans);
}
