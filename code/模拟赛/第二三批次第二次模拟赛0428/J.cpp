#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 3e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
ll sum;
priority_queue<ll,vector<ll>, greater<ll> > q;
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++){
		ll a;
		cin >> a;
		q.push(a);
	}
	while(q.size() > 1){
		ll t = q.top();
		q.pop();
		sum += t + q.top();
		t += q.top();
		q.pop();
		q.push(t);
	}
	cout << sum;
	return 0;
}
