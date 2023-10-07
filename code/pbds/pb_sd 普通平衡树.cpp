#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
using namespace __gnu_pbds;
tree<pair<int,int>, null_type,less<pair<int,int> > ,rb_tree_tag,tree_order_statistics_node_update> data;

int main(){
	int n, m, cnt = 0,last = 0,ans = 0;
	cin >> n >> m;
	for(int i =1,t; i <= n; i++){
		cin >> t;
		data.insert(make_pair(t,cnt++));
	}
	for(int i = 1; i <= m; i++){
		int op, x;
		cin >> op >> x;
		x ^= last;
		if(op == 1){
			data.insert(make_pair(x,cnt++));
		}
		if(op == 2){
			auto it = data.lower_bound(make_pair(x,0));
			data.erase(it);
		}
		if(op == 3){
			last = data.order_of_key(make_pair(x,0))+1; 
		}
		if(op == 4){
			last = data.find_by_order(x  - 1)->first;
		}
		if(op == 5){
			last = data.find_by_order(data.order_of_key(make_pair(x, 0)) - 1)->first;
		}
		if(op == 6){
			last = data.find_by_order(data.order_of_key(make_pair(x, 2147483647)))->first;
		}
		if(op > 2) ans ^= last;
	}
	cout << ans;
	return 0;
}
