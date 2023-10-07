#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int ans[20];
bool v[20];
void print() {
	for (int i = 0; i < n; i++) {
		cout << "    " << ans[i] ;
	}
	cout << endl;
}
void dfs(int step) {
	if (step == n) {
		print();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {
			v[i] = 1;
			ans[step] = i;
			dfs(step + 1);
			v[i] = 0;
		}
	}
	return;
}
int main() {
	cin >> n;
	dfs(0);
	return 0;
}
