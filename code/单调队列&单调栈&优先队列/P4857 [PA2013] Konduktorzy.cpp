#include <bits/stdc++.h>
const int N = 1e5+10;
using namespace std;
#define int long long
int n, num[N];
int m, temp, ans[N];

inline bool check(int mid) {
	int t = m;
	for (int i = 1; i <= n; ++i) {
		t -= mid / num[i];
		if (t < 0)
			return 0;
	}
	return 1;
}
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > q;


signed main() {
	cin >> m >> n;
	for (int i = 1; i <= n; ++i){
		cin >> num[i];
	}
	int r = 1e18 ,l = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid))
			temp = mid, l = mid + 1;
		else
			r = mid - 1;
	}
//	cout << temp << endl;
	int t = temp;
	for (int i = 1; i <= n && t; ++i) t = min(t, max((temp / num[i] - 1) * num[i], 0ll));
//	cout << t << endl; 
	int used = 0;
	for (int i = 1; i <= n; ++i) {
		used += t / num[i];
		q.push( {t / num[i] * num[i],i});
	}
	while (used < m) {
		auto tmp = q.top();
		q.pop();
//		cout << tmp.first << " " <<  tmp.second << endl;
		ans[tmp.second] = ++used;
		tmp.first += num[tmp.second];
//		cout << tmp.first << " xxx " <<  tmp.second << endl;
		q.push(tmp);
	}
	for (int i = 1; i < n; ++i) printf("%lld ", ans[i]);
	printf("%lld\n", ans[n]);
	return 0;
}

