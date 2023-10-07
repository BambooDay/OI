#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int>  Pair;
int n, m, l, ans;
int a[N],b[N];
priority_queue<Pair,vector<Pair>,greater<Pair> > q1,q2;

signed main(){
	cin >> l >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		q1.push(make_pair(a[i],i));
	}
	for(int i =1;i <= m; i++){
		cin >> b[i];
		q2.push(make_pair(b[i],i));
	}
	vector<int> cnt;
	cnt.push_back(0);
	for(int i = 1; i <= l; i++){
		Pair t = q1.top();
		q1.pop();
		q1.push(make_pair(t.first+a[t.second],t.second));
		cnt.push_back(t.first);
	}
	for(int i = l; i >= 1; i--){
		Pair t = q2.top();
		q2.pop();
		q2.push(make_pair(t.first+b[t.second],t.second));
		ans = max(ans,cnt[i]+t.first);
	}
	cout << ans;
	return 0;
}
