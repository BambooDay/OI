#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5+10;
const int M = 4e6+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[M],node[M];
int idx = 1;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int dfn[N],low[N];
int cnt = 0;
stack<int> st;
vector<vector<int> > ans;
void tarjan(int pos,int e){
	dfn[pos] = ++cnt;
	low[pos] = dfn[pos];
	st.push(pos);
	for(int i = h[pos];i;i = ne[i]){
		if(i == (e^1)) continue;
		int to = node[i];
		if(!dfn[to]){
			tarjan(to,i);
			low[pos] = min(low[pos],low[to]);
		}else{
			low[pos] = min(low[pos],dfn[to]);
		}
	}
	if(low[pos] == dfn[pos]){
		vector<int> v;
		v.push_back(pos);
		while(st.top() != pos){
			v.push_back(st.top());
			st.pop();
		}
		st.pop();
		ans.push_back(v);
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= m; i++){
		int x, y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	for(int i =1;i <= n; i++){
		if(!dfn[i]) tarjan(i,1);
	}
	cout << ans.size() << endl;
	for(vector<int> v : ans){
		cout << v.size() << " ";
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
