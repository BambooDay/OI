#include <bits/stdc++.h>
const int N = 505;

using namespace std;
struct Node{
	int id, x, y;
}a[N];
bool cmp(Node x, Node y){
	return x.x > y.x;
} 
int n,m;
bool vis[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++) a[i].id = i,vis[i] = 0;
	for(int i = 1;i <= n; i++) cin >> a[i].x;
	for(int i = 1;i <= n; i++) cin >> a[i].y;
	sort(a+1,a+1+n,cmp);
	int now = 0;
	while(a[now].id != m) now++;
	int ans = 0,mi = a[now].y;
	while(a[now+1].x == a[now].x) swap(a[now],a[now+1]),now++;
	for(int i = 1;i <= n; i++) if(a[i].x == a[now].x) a[now].y = max(a[now].y,a[i].y),ans++,vis[a[i].id] = 1;
	
//	for(int i = 1;i <= n; i++){
//		cout << a[i].x << " " << a[i].y << " " << a[i].id << endl;
//	}
	
	for(int i = 1; i <= now; i++){
		if(a[i].y < a[now].y && a[i].x != a[now].x&& !vis[a[i].id]) vis[a[i].id] = 1,ans++;
		mi = min(mi,a[i].y);
	}
	int ma = -1;
	for(int i = now+1; i <= n; i++){
		ma = max(a[i].y,ma);
		if(a[i].y > mi&& !vis[a[i].id]) vis[a[i].id] = 1,ans++;
	}
	for(int i = 1; i <= now; i++){
		if(a[i].y < ma && !vis[a[i].id]) vis[a[i].id] = 1,ans++;
	}
	cout << ans << endl; 
}
int main(){
	freopen("animal.in","r",stdin);
	freopen("animal.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();	
	return 0;
}
