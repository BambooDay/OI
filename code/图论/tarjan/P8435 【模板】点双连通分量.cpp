#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5+10;
const int M = 4e6+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[M],node[M],idx = 1;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

int dfn[N],low[N],cnt = 0;
int rt;
vector<vector<int> > ans;
stack<int> st;
void tarjan(int pos,int e){
	dfn[pos] = ++cnt;
	low[pos] = dfn[pos];
	int son = 0;
	st.push(pos);
	for(int i = h[pos];i;i = ne[i]){
		if(i == (e ^ 1)) continue;
		int to = node[i];
		if(!dfn[to]){
			son++;
			tarjan(to,i);
			low[pos] = min(low[pos],low[to]);
			if(dfn[pos] <= low[to]){
				vector<int> v;
				v.push_back(pos);
				while(st.top() != to){
					v.push_back(st.top());
					st.pop();
				}
				st.pop();
				v.push_back(to);
				ans.push_back(v);
			}
		}else low[pos] = min(low[pos],dfn[to]);
		
	}
	if(pos == rt && son == 0){
		vector<int> v;
		v.push_back(pos);
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
	for(int i = 1;i <= n; i++){
		if(!dfn[i]) rt = i,tarjan(i,0);
	}
	cout << ans.size() << endl;
	for(auto v : ans){
		cout << v.size() << " ";
		for(int i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
