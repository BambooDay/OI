#include <bits/stdc++.h>

using namespace std;
char now = 'a';
char pre[130];
bool ne[130];
int n;
int t;
string s;
int cnt;
int fa[130];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
} 
void solve(){
	for(int i = 'a'; i <= 'z'; i++){
		fa[i] = i;
		ne[i] = 0;
		pre[i] = 0;
	}
	cnt = 0;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		if(pre[s[i]]){
			cout << pre[s[i]];
			continue;
		}
		for(char j = 'a'; j <= 'z'; j++){
			int fi = find(s[i]),fj = find(j);
			if(!ne[j] && (fi != fj || cnt == 25)){
				ne[j] = 1;
				pre[s[i]] = j;
				cnt++;
				fa[fj] = fi;
//				cout << i << endl;
				break;
			}
		}
		cout << pre[s[i]];
	} 
	cout << endl;
}
int main(){
	freopen("encode.in","r",stdin);
	freopen("encode.out","w",stdout);
	cin >> t;
	while(t--) solve();
	return 0;
}
