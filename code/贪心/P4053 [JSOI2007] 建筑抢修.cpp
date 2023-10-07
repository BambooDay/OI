#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;
using namespace std;
pair<int,int> a[N];
int n;
priority_queue<int> q;
int sum;
int ans;
signed main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].second >> a[i].first;
	}		
	sort(a+1,a+1+n);
	for(int i = 1;i <= n; i++){
		sum += a[i].second;
		ans++;
		q.push(a[i].second);
		if(sum > a[i].first){
			sum-= q.top();
			q.pop();
			ans--;
		} 
	}	
	cout << ans;
	return 0;
}
