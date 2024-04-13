#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
stack<int> st;
int n;
int a[N];
int ans[N];

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];		
	}	
	for(int i = 1;i <= n; i++){
		char op;
		cin >> op;
		if(op == 'L'){
			if(st.empty()){
				ans[i] = -1;
				continue;
			}
			int t = st.top();
			st.pop();
			int res = a[i] - a[t]; 
			ans[i] = ans[t] = res;
//			cout << res << "\n";
		}else{
			st.push(i);
		}
	}
	while(!st.empty()){
		ans[st.top()] = -1;
		st.pop();
	}
	for(int i = 1; i < n; i++) cout << ans[i] << " ";
	cout << ans[n];
	return 0;
}
