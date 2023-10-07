#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 200+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int h[N],ne[N*N],node[N*N],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

int match[N],v[N];
bool find(int pos){
//	cout<< endl << pos << ": ";
	for(int i = h[pos];i;i = ne[i]){
		int to = node[i];
//		cout << to << " ";
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
void solve(){
	int n;
	cin >> n;
	int sum = 0;
	memset(h,0,sizeof h);
	idx = 0;
	memset(match,0,sizeof match);
	int live[60] = {0};
	for(int i =1;i <= n; i++){
		cin >> live[i];
		if(live[i] == 0) sum++;
	}
	int home[60]={0};
	for(int i =1 ;i <= n; i++){
		cin >> home[i];
		if(live[i] == 1 && home[i] == 0){
			sum++;
			add(i,i);
		}
	}
	for(int i =1;i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(x == 1 && live[j] == 1){
				add(i,j);
			}
		}
	}
	int tot = 0;
	for(int i  = 1; i <= n; i++){
		if((live[i] && !home[i])||!live[i]){
			memset(v,0,sizeof v);
			if(find(i)){
				tot++;
			}
		}
	}
	if(tot==sum) cout<<"^_^"<<endl;
	else cout<<"T_T"<<endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
