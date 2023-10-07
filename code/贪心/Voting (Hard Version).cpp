#include <bits/stdc++.h>
const int N = 2e5+10;
#define int long long
using namespace std;
vector<int> t[N];
void solve(){
	int n;
	long long sum = 0;
	priority_queue<int> q;
	cin >> n;
	for(int i = 0; i <= n; i++) t[i].clear();
	for(int i  = 1;i <= n; i++){
		int a,b;
		cin >> a >> b;
		t[a].push_back(b);
		sum += b;
	}
	for(int i = 0; i <= n; i++){
		if(!q.empty()){
			sum -= q.top();
			q.pop();
		}
		for(int i:t[i]){
			q.push(i);
		}
	}
	cout << sum << endl;
	
} 
signed main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
