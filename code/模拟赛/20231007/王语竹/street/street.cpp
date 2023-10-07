#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
using namespace std;
int n,q;
int a[N];
vector<int> e[N];
void add(int pos, int d,int fa, int w, int p){
	if((!w / pow(p,d))) return;
	a[pos] += w / pow(p,d);
//	cout << a[pos] << endl;
	for(int to : e[pos]){
		if(to == fa) continue;
		add(to,d+1,pos,w,p);
	}
} 
int ask(int pos, int fa){
	int res = a[pos];
	for(int to : e[pos]){
		if(to == fa) continue;
		res += ask(to,pos);
	}
	return res;
}
signed main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int u,w,p;
			cin >> u >> w >> p;
			add(u,0,0,w,p); 
		} else{
			int u,v;
			cin >> u >> v;
			cout << ask(u,v) << " " << ask(v,u) << endl;
		}
	}
	
	return 0;
}
