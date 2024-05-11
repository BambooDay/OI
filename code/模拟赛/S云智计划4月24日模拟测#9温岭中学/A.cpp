#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n;
int a[N];
bool f = 1;
bool v[N*1000];
//set<int> s;
signed main(){
	freopen("stone.in","r",stdin);
//	freopen("stone.out","w",stdout);
	cin >>  n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f = (a[i] == 1);
	}	
	if(f){
		cout << n+1 << "\n";
		return 0;
	}
	vector<int> vec;
	for(int i = 1;i <= n; i++){
		vector<int> ve;
		for(auto x : vec){
			int t = x+a[i];
//			cout << t << " ";
			ve.push_back(t);
			v[t] = 1;
		}	
		for(int t : ve) vec.push_back(t);
		vec.push_back(a[i]);
//		s.insert(a[i]);
		v[a[i]] = 1;
		cout << vec.size() << " ";
	}
	for(int i = 1; i <= 1e8; i++){
		if(!v[i]){
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}
