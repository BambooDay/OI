#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
struct Place {
	int val,l,r;
} p[N];
struct Node {
	int val,id;
	bool operator <(Node it) const {
		return val>it.val;
	}
};
int n,m,ans,last;
bool vis[N];
priority_queue<Node> q;
void del(int x) {
	p[x].l=p[p[x].l].l;
	p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;
	p[p[x].r].l=x;
}
void solve(){
	memset(vis,0,sizeof vis);
	memset(p,0,sizeof p);
	ans = 0;
	while(!q.empty()) q.pop();
	cin >> n >> m >> last;
//	cin >> m >> n >> last;
	for(int i=1; i<n; ++i) {
		int a;
		cin >> a;
		p[i].val=a-last;
		last=a;
		p[i].l=i-1;
		p[i].r=i+1;
		q.push((Node) {p[i].val,i});
	}
	p[0].val=p[n].val=1e9;
	for(int i=1; i<=m; ++i) {
		while(vis[q.top().id]) q.pop();
		Node now=q.top();
		q.pop();
		ans+=now.val;
		vis[p[now.id].l]=vis[p[now.id].r]=1;
		p[now.id].val=p[p[now.id].l].val+p[p[now.id].r].val-p[now.id].val;
		q.push((Node){p[now.id].val,now.id});
		del(now.id);
	}
	printf("%d\n",ans);
} 
signed main() {
	solve();
	return 0;
}

