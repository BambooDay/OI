#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 2e5+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m;

vector<pair<int,bool> > e[N];

int in[N],st[N];
stack<int> s;
void dfs(int x){
//	cout << x << endl;
	for(int to = 0; to < e[x].size(); to = max(to+1,st[x])){
		if(!e[x][to].second){
			e[x][to].second = 1;
			st[x] = to+1;
			dfs(e[x][to].first);
		}
	}
	s.push(x);
}
int main(){
//	freopen("P7771_10.in","r",stdin);
	scanf("%d%d",&n,&m);
//	cin >> n >> m;
	int t = m;
	while(t--){
		int u, v;
//		cin >> u >> v;
		scanf("%d%d",&u,&v);
		e[u].push_back(make_pair(v,0));
		in[v]++;
		in[u]--;
	}	
	int fb=0,fe=0,pb=1,pe;
	for(int i =1;i <= n; i++){
		if(abs(in[i]) > 1){
			puts("No");
			return 0;
		}
		if(in[i]==1) fe++,pe=i;
		if(in[i]==-1) fb++,pb=i;
		if(fb>1||fe>1) {
			printf("No");
			return 0;
		}
		sort(e[i].begin(),e[i].end());
	}
	dfs(pb);
	if(s.size() != m+1){
		puts("No");
		return 0; 
	}
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
