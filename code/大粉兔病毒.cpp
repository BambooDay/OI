#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m;
vector<int> e[N];
int st;
int v[N];
bool in[N];
queue <int > q;
int ans = 0;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x); 
	}
	cin >> st;
	q.push(st);
	memset(v,0x3f,sizeof v);
	v[st] = 1;
	in[st] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		in[x] = 0;
//		cout << endl << v[x] << ": ";
		for(auto to : e[x]){
			if(!in[to]){
				if(v[to] == v[x] - 1 || v[to] == v[x]) continue;
				if(v[to] != INF){
					cout << -1;
					return 0;
				}
				q.push(to);
				in[to] = 1;
				v[to] = v[x] + 1;
//			cout << to << "&" << v[to] << " ";
			}
		}
		ans = v[x];
	}
	cout << ans;
	return 0;
}
