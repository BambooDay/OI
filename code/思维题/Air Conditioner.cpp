#include <bits/stdc++.h>

using namespace std;
struct Node{
	int id,l,r;
}a[200];
bool cmp(Node x, Node y){
	return x.id < y.id;
}
int n,m;
void solve(){
	cin >> n >> m;
	int L,R;
	L = R = m;
	for(int i = 1; i <= n; i++) cin >> a[i].id >> a[i].l >> a[i].r;
	sort(a+1,a+1+n,cmp);
	int last = 0;
	for(int i = 1; i <= n; i++){
		L -= (a[i].id - last);
		R += (a[i].id - last);
//		cout << L << " " << R << " ";
		L = max(L,a[i].l);
		R = min(R, a[i].r);
//		cout << L << " " << R << endl;
		if(L > R){
			cout << "NO" << endl;
			return;
		}
		last = a[i].id;
	}
	cout << "YES" << endl;
	return;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
} 
