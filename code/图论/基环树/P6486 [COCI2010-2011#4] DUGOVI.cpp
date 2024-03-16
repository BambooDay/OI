#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n,fa[N],val[N],in[N],now[N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> fa[i] >> val[i];
		in[fa[i]]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!in[i]){
			for(int u = i; !in[u]; u = fa[u]){
				ans += max(val[u]-now[u],0);
				in[fa[u]]--;
				now[fa[u]] += val[u];
				in[u] = -1; 
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(in[i] > 0){
			int res = 1e9;
			for(int u = fa[i],su = i;in[u] > 0; su = u,u = fa[u]){
				int c1 = max(val[u]-val[su]-now[u],0),c2 = max(val[u]-now[u],0);
				ans += c1;
				if(res > c2-c1) res = c2-c1;
				in[u] = 0;
			}
			ans += res;
		}
	}
	cout << ans;
	return 0;
}
