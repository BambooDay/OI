#include <bits/stdc++.h>
const int N = 1e4+10;
const int M = 5e4+10;

using namespace std;
vector<int> e[N];
int n, m;
int dfn[N],low[N];
bool in[N];
stack<int> st;
int cnt;
int sum = 0;
void tarjan(int pos){
	dfn[pos] = low[pos] = ++ cnt;
	st.push(pos);
	in[pos] = 1;
	for(int to : e[pos]){
		if(!dfn[to]){
			tarjan(to);
			low[pos] = min(low[pos],low[to]);
		}else{
			if(in[to]){
				low[pos] = min(low[pos],dfn[to]);
			}
		}
	}
	if(low[pos] == dfn[pos]){
		if(st.top()!=pos)sum++;
		while(st.top() != pos){
			int t = st.top();
			st.pop();
			in[t] = 0;
		}
		st.pop();
		in[pos] = 0;
	}
} 
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	for(int i = 1;i <= n; i++){
		if(!dfn[i]) tarjan(i);
	}
	cout << sum;
	return 0;
}
