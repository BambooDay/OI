#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e8+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m, k;
int fa[N];
int get(int x){
	return fa[x] == x ? x:fa[x] = get(fa[x]);
}
struct edge{
	int u, v;
}e[N];
int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1;i <= m; i++){
		 cin >> e[i].u >> e[i].v;
		 if(e[i].u > k && e[i].v > k) fa[get(e[i].u)] = get(e[i].v);
	}
	
	int sum = 0;
	for(int i = 1; i <= m; i++){
		if(e[i].u <= k || e[i].v <= k){
			if(get(e[i].u) == get(e[i].v)) sum++;
			else fa[get(e[i].u)] = get(e[i].v);
		} 
	}
	cout << sum << endl;
	return 0;
}
