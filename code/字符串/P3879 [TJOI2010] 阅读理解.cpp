#include <bits/stdc++.h>

using namespace std;
int n, m;
map<string ,set<int> > cnt;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for(int j =1; j <= x; j++){
			string s;
			cin >> s;
			cnt[s].insert(i);
		}
	}
	cin >> m;
	while(m--){
		string s;
		cin >> s;
		if(!cnt.count(s)){
			cout << endl;
			continue;
		}
		for(auto it : cnt[s]){
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}
