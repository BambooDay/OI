#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e4+10;
const int M = 2e5+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[M],node[M];
int idx = 1;
void add(int u,int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

int dfn[N],low[N];
int cnt = 0;
bool ans[N];
int rt;
void tarjan(int pos,int e){
	dfn[pos] = ++cnt;
	low[pos] = dfn[pos];
	int son = 0;
	for(int i = h[pos];i;i=ne[i]){
		int to = node[i];
		if(i == (e^1)) continue;
		if(!dfn[to]){
			tarjan(to,i);
			low[pos] = min(low[pos],low[to]);
			if(dfn[pos] <= low[to]&&pos!= rt){
				ans[pos] =1;
			}
			son++;
		}else{
			low[pos] = min(low[pos],dfn[to]);
		}
	}
	if(son > 1 && pos == rt) ans[pos] = 1;
}
int main(){
//	freopen("P3388_1.in","r",stdin);
	int n, m;
	cin >> n >> m;
	for(int i =1;i <= m; i++){
		int x, y;
		cin >> x >> y;
		add(x,y);
		add(y,x);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]) rt=i,tarjan(i,0);
	}
	vector<int> res;
	for(int i =1;i <= n; i++){
		if(ans[i]) res.push_back(i);
	}
	cout << res.size() << endl;
	for(int i : res) cout << i << " ";
	return 0;
}
