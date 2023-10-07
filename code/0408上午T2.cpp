#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e3+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int k;
vector<int> e[N];
int en;
struct triplet{
	int dis,id,pre;
	triplet(int _dis,int _id, int _pre):dis(_dis),id(_id),pre(_pre){}
};
struct cmp{
	bool operator()(const triplet x, const triplet y){
		if(x.dis != y.dis) return x.dis < y.dis;
		if(x.pre != y.pre) return x.pre < y.pre;
		return x.id < y.id;
	}
};
pair <int, int> ans[N];
void dijstra(){
	priority_queue<triplet,vector<triplet>,cmp> q;
	q.push(triplet(0,0,0));
	while(!q.empty()){
		int node = q.top().id;
		if(ans[node].first) {
			q.pop();
			continue;
		}
		ans[node].second = q.top().pre;
		ans[node].first = q.top().dis;
		q.pop();
		if(node == en){
			return;
		}
		for(auto j : e[node]){
			if(ans[j].second) continue;
			q.push(triplet(ans[node].first+1, j, node));
		}
	}
}
int main(){
	cin >> k;
	for(int i = 1; i <= k; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
	}
	int a, b;
	cin >> en >> a >> b;
	e[0].push_back(a);
	e[0].push_back(b);
	dijstra();
	cout << ans[en].first << endl;
	int node = en;
	while(node){
		cout << ans[node].second << " ";
		node = ans[node].second;
	}
	return 0;
}
