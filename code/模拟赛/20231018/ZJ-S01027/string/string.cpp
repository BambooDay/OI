#include <bits/stdc++.h>

using namespace std;
int h[30],node[1005],ne[1005],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
bool g[30][30];
int deg[30];

bool check(){
	queue<int> q;
	for(int i = 1;i <= 26; i++){
		if(!deg[i]){
			q.push(i);
		}
	}
	int cnt = 0;
	while(!q.empty()){
		int u = q.front();
		cnt++;
		q.pop();
		for(int i = h[u];i;i = ne[i]){
			int to = node[i];
			deg[to]--;
			if(!deg[to]){
				q.push(to);
			}
		}
	}
	if(cnt < 26) return 0;
	else return 1;
}
void init(){
	for(int i = 1;i <= 26;i++){
		h[i] = 0;
		deg[i] = 0;
		for(int j =1;j <= 26; j++){
			g[i][j] = 0;
		}
	}
	//memset(g,0,sizeof g);
	//memset(h,0,sizeof h);
	//memset(deg,0,sizeof deg);
	idx = 0;
}
string s[30005];
int n;
vector<string> ans;
void calc(int id){
	init();
	for(int i = 1; i <= n; i++){
		if(i == id) continue;
		string t = s[i];
		bool flag = 1;
		for(int j = 0; j < min(t.size(),s[id].size()) && flag; j++){
			if(t[j] != s[id][j]){
				flag = 0;
				int u = s[id][j] - 'a'+1,v = t[j]-'a'+1;
				if(!g[u][v]){
					g[u][v] = 1;
					deg[v]++;
					add(u,v);
				}
			}
		}
		if(flag && t.size() < s[id].size()) return;
	}
	if(check()){
		ans.push_back(s[id]);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i =1;i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++) calc(i);
	cout << ans.size() << endl;
	for(string i : ans) cout << i << endl;
	return 0;
}