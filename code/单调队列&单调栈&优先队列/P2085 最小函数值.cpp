#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int a[N],b[N],c[N];
int n,m;
struct Node{
	int val, id, now;
	friend bool operator < (Node x, Node y){
		return x.val > y.val;
	}
}; 
priority_queue<Node> q;

signed main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i] >> b[i] >> c[i];
		q.push({a[i]+b[i]+c[i],i,1});
	}
	while(m--){
		Node u = q.top();
		q.pop();
		cout << u.val << " ";
		u.now++;
		u.val = a[u.id]*u.now*u.now+b[u.id]*u.now+c[u.id];
		q.push(u);
	}
	return 0;
} 
