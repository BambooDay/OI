#include <bits/stdc++.h>
using namespace std;
struct Trie{
	Trie *fa;
	int siz;
	unordered_map<int,Trie*>son;
	Trie(Trie *f){
		fa = f;
		siz = 0;
	}
};
int n;
long long ans;
void solve(){
	cin >> n;
	ans = 0;
	Trie *rt = new Trie(NULL);
	rt->siz++;
	stack<int> st;
	for(int i = 1;i <= n; i++){
		int a;
		cin >> a;
		if(st.empty() || st.top() != a){
			st.push(a);
			rt = rt->son.emplace(a,new Trie(rt)).first->second;
		}else{
			rt = rt->fa;
			st.pop();
		}
		ans += rt->siz++;
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
