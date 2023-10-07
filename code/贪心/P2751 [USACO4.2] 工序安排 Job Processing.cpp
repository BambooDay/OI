#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;
using namespace std;
int a[N],b[N];
int n , m, l;
priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> >  > wash,cook;
int t[N];
signed main(){
	cin >> l >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		wash.push({a[i],a[i]});
	}
	for(int i =1;i <= l; i++){
		pair<int,int> x = wash.top();
		wash.pop();
		t[i] = x.first;
		x.first += x.second;
		wash.push(x);
	}
	for(int i = 1;i <= m; i++){
		cin >> b[i];
		cook.push({b[i],b[i]});
	}
	int ans = 0;
	for(int i = l; i; i--){
		pair<int,int> x = cook.top();
		cook.pop();
		if(x.first+t[i] > ans) ans = x.first + t[i];
		x.first += x.second;
		cook.push(x);
	}
	cout << t[l] << " " << ans;
	return 0;
} 
