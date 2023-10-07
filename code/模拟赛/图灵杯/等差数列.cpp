#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a[30005];
int l1, l2, r1, p1[30005], p2[30005];

bool f(int dif) {
	int pre = p2[l2];
	for (int i = l2 - 1; i >= 1;) {
		if (pre - p2[i] == dif)
			pre = p2[i], i--;
		else if (pre - p1[r1] == dif)
			pre = p1[r1], r1--;
		else
			return false;
	}
	return true;
}

void solve(int st, int dif) {
	l1 = l2 = 0;
	for (int i = 1; i < st; i++)
		p2[++l2] = a[i];
	int now = a[st];
	for (int i = st; i <= n; i++)
		if (a[i] == now)
			p1[++l1] = a[i], now += dif;
		else
			p2[++l2] = a[i];
	if (l2 == 0) {
		for (int i = 1; i < l1; i++)
			cout << p1[i] << ' ';
		cout << endl << p1[l1] << endl;
		exit(0);
	}
	if (l2 == 1) {
		for (int i = 1; i <= l1; i++)
			cout << p1[i] << ' ';
		cout << endl;
		for (int i = 1; i <= l2; i++)
			cout << p2[i] << ' ';
		cout << endl;
		exit(0);
	}
	r1 = l1;
	if (f(p2[l2] - p2[l2 - 1])) {
		for (int i = 1; i <= r1; i++)
			cout << p1[i] << ' ';
		cout << endl;
		int d = p2[l2] - p2[l2 - 1];
		int pre = p2[1];
		cout << p2[1] << ' ';
		for (int i = 2; i <= l2;)
			if (p2[i] - pre == d)
				cout << p2[i] << ' ', pre = p2[i], i++;
			else
				cout << p1[++r1] << ' ', pre = p1[r1];
		cout << endl;
		exit(0);
	}
	r1 = l1;
	if (f(p2[l2] - p1[l1])) {
		for (int i = 1; i <= r1; i++)
			cout << p1[i] << ' ';
		cout << endl;
		int d = p2[l2] - p1[l1];
		int pre = p2[1];
		cout << p2[1] << ' ';
		for (int i = 2; i <= l2;)
			if (p2[i] - pre == d)
				cout << p2[i] << ' ', pre = p2[i], i++;
			else
				cout << p1[++r1] << ' ', pre = p1[r1];
		cout << endl;
		exit(0);
	}
}

signed main() {
	int t;
	cin >> t;
	while(t--){	
		cin >> n;
		for (int i = 1; i <= n; cin >> a[i++]);
		solve(1, a[2] - a[1]);
		solve(1, a[3] - a[1]);
		solve(2, a[3] - a[2]);
		puts("No solution");
	} 
	return 0;
}
