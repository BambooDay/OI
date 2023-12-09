#include <bits/stdc++.h>
const int N = 30;

using namespace std;
int n,h[N],ans;
map<int,bool> m;
void dfs(int dep, int rest){
	if(!rest){
		int cnt = n*n;
		for(int i = 1; i < dep; i++){
			cnt -= h[i]*h[i];
		}
		cnt /= 2;
		if(!m[cnt]) ans++,m[cnt] = 1;
		return;
	}
	for(int i = h[dep-1]; i <= rest; i++){
		h[dep] = i;
		dfs(dep+1,rest - i);
	}
}
int main(){
	cin >> n;
	h[0] = 1;
	dfs(1,n);
	cout << ans << endl;
	return 0;
}
