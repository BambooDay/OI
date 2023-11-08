#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
priority_queue<pair<int,int> > q;
int n,k;
long long ans = 0;
 
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n; i++){
		int a,b;
		cin >> a >> b;
		if(a-b > 0) q.push({a-b,b});
	}	
	while(!q.empty() && k--){
		auto u = q.top();
		q.pop();
		ans += u.first;
		u.first -= 2*u.second;
		if(u.first <= 0) continue;
		q.push(u);
	}
	cout << ans << endl;
	return 0;
}
