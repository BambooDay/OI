#include <bits/stdc++.h>
#define int long long
const int N = 5e3+10;
const int mod = 998244353;
using namespace std;
int n,m;
vector<int> e[N];
int a[N];
int pw[N];
int ans = 0;
void check(int pos,int mi, int &k){
	if(a[pos] <= mi) k++;
	for(int to : e[pos]){
		check(to, min(mi,a[pos]),k);
	}
}
bool vis[N];
//int cnt[N];
void dfs(int step){
	if(step > n){
		int k = 0;
		check(1,N,k);
		//cout << k  << endl;
		//cnt[k]++;
		//for(int i = 1;i <= n; i++) cout << a[i] << endl;
		//exit(0);
		ans = (ans + pw[k]) % mod;
	}
	for(int i = 1;i <= n; i++){
		if(!vis[i]){
			a[step] = i;
			vis[i] = 1;
			dfs(step+1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("treecount.in","r",stdin);
	freopen("treecount.out","w",stdout);
	cin >> n >> m;
	pw[0] = 1;
	for(int i =1;i <= n; i++){
		pw[i] = pw[i-1] * m % mod;
	}
	for(int i =1;i < n; i++){
		int x; 
		cin >> x;
		e[x].push_back(i+1);
	}
	dfs(1);
	//for(int i = 1;i <= n; i++) cout << cnt[i] << " ";
	//cout << endl;
	cout << ans  << endl;
	return 0;
}