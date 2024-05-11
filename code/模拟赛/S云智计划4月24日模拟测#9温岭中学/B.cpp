#include <bits/stdc++.h>

using namespace std;
string s,t;
int fa[150],son[150];

void solve(){
	cin >> s >> t;
	int n = s.size();
	for(int i = 'a'; i <= 'z'; i++) fa[i] = 0,son[i] = 0;
	for(int i = 0; i < n; i++){
		int x = s[i],y = t[i];
		if(fa[x] && fa[x] != y || son[y] && son[y] != x){
			puts("No");
			return;
		}
		fa[x] = y;		
		son[y] = x;
	}
	puts("Yes");
}
int main(){
	freopen("cipher.in","r",stdin);
	freopen("cipher.out","w",stdout);
	int T;
	cin >> T;
	while(T--) solve();
		
	return 0;
}
