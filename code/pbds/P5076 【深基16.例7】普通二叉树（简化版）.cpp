#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update> data;
int n,cnt = 0;

int main(){
//	data.insert(make_pair(1,0));
//	data.insert(make_pair(1,-2));
//	cout << data.order_of_key(make_pair(1,-1)) << endl;
	cin >> n;
	while(n--){
		int op,x;
		cin >> op >> x;
		if(op == 1){
			cout << (data.order_of_key(make_pair(x,0)))+1 << endl;
		} 
		if(op == 2){
			auto it = data.find_by_order(x-1);
			cout << it->first << endl;
		}
		if(op == 3){
			if(data.order_of_key(make_pair(x, 0)) == 0){
				cout << -2147483647 << endl;
				continue;
			}
			cout << data.find_by_order(data.order_of_key(make_pair(x, 0)) - 1)->first << endl;
		}
		if(op == 4){
			if(data.order_of_key(make_pair(x, 2147483647)) == cnt){
				cout << 2147483647 << endl;
				continue;
			}
			cout << data.find_by_order(data.order_of_key(make_pair(x, 2147483647)) )->first << endl;
		}
		if(op == 5){
			data.insert(make_pair(x,++cnt));
		}
	}
	return 0;
}
