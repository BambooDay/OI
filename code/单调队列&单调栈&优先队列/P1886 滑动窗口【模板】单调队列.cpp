#include <bits/stdc++.h>
#define int long long
const int N = 1e6 + 10;
using namespace std;
int a[N], n, k;

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> q1;
	for (int i = 1; i <= n; i ++) {
		while (!q1.empty() && q1.front() <= (i - k)) q1.pop_front();
		while (!q1.empty() && a[q1.back()] >= a[i]) q1.pop_back();
		q1.push_back(i);
		if (i >= k) cout << a[q1.front()] << " ";
	}
	puts("");
	deque<int> q;
	for (int i = 1; i <= n; i ++) {
		while (!q.empty() && q.front() <= (i - k)) {
//			cout << q.front() << endl;
			q.pop_front();
		}
		while (!q.empty() && a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
		if (i >= k ) cout << a[q.front()] << " ";
	}
	return 0;
}
