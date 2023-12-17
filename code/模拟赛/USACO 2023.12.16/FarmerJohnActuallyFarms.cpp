#include <bits/stdc++.h>
const int N = 2e5+10;
#define int long long
using namespace std;
struct tr{
	int h,a,id;
}Node[N];
int n;
bool cmp(tr x, tr y){
	return x.id > y.id;
}
int check(){
	int t = 0;
//	for(int i = 1; i <= n;i++){
//		cout << Node[i].h << " " << Node[i].a << " " << Node[i].id << endl; 
//	}
	for(int i = 2; i <= n; i++){
		int h = Node[i-1].h+Node[i-1].a*t,a1 = Node[i-1].a;
		int h2 = Node[i].h+Node[i].a*t,a2 = Node[i].a;
		if(h < h2) continue;
		if(h >= h2 && a1 >= a2) return -1;
//		cout << h << " " << h2 << " " << a1 << " " << a2 <<endl;
//		cout << (h-h2+1) / (a2-a1) + !!((h-h2+1)%(a2-a1)) << endl;
		t += (h-h2+1) / (a2-a1) + !!((h-h2+1)%(a2-a1));
	}
	for(int i = 1; i <= n; i++){
		Node[i].h += Node[i].a*t;
	}
	for(int i = 1; i < n; i++){
		if(Node[i].h >= Node[i+1].h) return -1;
	}
	return t;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> Node[i].h; 
	}	
	for(int i = 1; i <= n; i++) cin >> Node[i].a;
	for(int i = 1;i <= n; i++){
		cin >> Node[i].id;
	}
	sort(Node+1,Node+1+n,cmp);
	cout << check() << endl;	
}
signed main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
//2
//7 7
//8 8
//0 1
