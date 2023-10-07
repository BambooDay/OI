#include <bits/stdc++.h>
const int N = 1010;
using namespace std;
int n,m,E;
vector<int> e[N];
int match[N];
bool v[N];
bool find(int pos){
	for(int to : e[pos]){
		if(!v[to]){
			v[to] = 1;
			int t = match[to];
			if(!t || find(t)){
				match[to] = pos;
				return 1;
			}
		}
	}
	return 0;
}
int cnt = 0;
int main(){
	cin >> n >> m >> E;
	for(int i = 1;i <= E; i++){
		int u,v;
		cin >>u >> v;
		e[u].push_back(v+500);
		e[v+500].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		memset(v,0,sizeof(v));
		if(find(i)) cnt++; 
	}
	cout << cnt;
	return 0;
}
