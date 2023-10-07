#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n,A,B;
int k;
bool v[300];
vector<int> e[300];
ll dis[300];
int main(){
	cin >> n >> A >> B;
	for(int i =1; i <= n; i++){
		cin >> k;
		if(i + k <= n) e[i].push_back(i+k);
		if(i - k > 0) e[i].push_back(i-k);
		dis[i] = -1;
	}
	queue<int> q;
	q.push(A);
	dis[A] = 0;
	while(!q.empty()){
		int t = q.front();
//		cout<< t << " ";
		q.pop();
		if(t == B){
			cout << dis[t];
			return 0;
		}
		for(int to : e[t]){
			if(!v[to]){
				dis[to] = dis[t]+1;
				v[to] = 1;
				q.push(to);
			}
		}
	}
	cout << -1;
	return 0;
}
