#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
tree<pair<long long ,int>, null_type,less<pair<long long,int> > , rb_tree_tag, tree_order_statistics_node_update> data;

long long sum;
int n;
int cnt = 0;
int  main(){
	cin >> n;
	cin >> sum;
	data.insert(make_pair(sum,++cnt));
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		int order = data.order_of_key(make_pair(x,114514));
//		cout << order << " ";
		if(order == 0){
			sum += abs(data.find_by_order(0)->first - x);
		}else if(order == cnt){
//			cout<< data.find_by_order(cnt-1)->first << "xxx" << endl;
			sum += abs(data.find_by_order(cnt-1)->first - x);
		}else{	
//			cout << data.find_by_order(order-1)->first << " ";
			sum += min(abs(data.find_by_order(order-1)->first - x),abs(data.find_by_order(order)->first - x)); 
		}
//		cout << sum << "xxx" << endl;; 
		data.insert(make_pair(x,++cnt));
	}
	cout << sum;
	return 0;
}
