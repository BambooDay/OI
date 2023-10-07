#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n, m, q, u, v, t, a[7500000], ans[7500000], s = 0, y = 0, tot = 0;
queue<ll> q1, q2, q3;
ll getmax() {                  
	int x1 = -(1 << 30), x2 = x1, x3 = x1;
	if (!q1.empty())x1 = q1.front();
	if (!q2.empty())x2 = q2.front();
	if (!q3.empty())x3 = q3.front();
	if (x1 >= x2 && x1 >= x3) {
		q1.pop();
		return x1;
	} else if (x2 >= x1 && x2 >= x3) {
		q2.pop();
		return x2;
	}
	q3.pop();
	return x3;
}
void put(ll x1, ll x2) {                  //压入两条新蚯蚓
	if (x1 < x2) {
		swap(x1,x2);
	}
	q2.push(x1), q3.push(x2);
	return;
}
bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	cin >> n >> m >>  q >>u >> v >> t;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (ll i = 1; i <= n; i++)q1.push(a[i]);
	for (ll i = 1; i <= m; i++) {
		ans[i] = getmax() + y;
		int j = ans[i] * u / v, k = ans[i] - j;
		y += q;
		put(j - y, k - y);
	}
	while (!q1.empty() || !q2.empty() || !q3.empty())a[++tot] = getmax() + y;
	for (int i = t; i <= m; i += t)cout << ans[i] << " ";
	cout << endl;
	for (int i = t; i <= tot; i += t)cout << a[i] << " ";
	return 0;
}
 
