#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6 + 10;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n,r;
int ans[30];
bool v[30];
void print() {
	for (int i = 0; i < r; i++) {
		cout << setw(3)<< ans[i] ;
	}
	cout << endl;
}
void dfs(int step,int fa) {
	if (step == r) {
		print();
		return;
	}
	for (int i = fa+1; i <= n; i++) {
		if (!v[i]) {
			v[i] = 1;
			ans[step] = i;
			dfs(step + 1,i);
			v[i] = 0;
		}
	}
	return;
}
int main() {
	cin >> n >> r;
	dfs(0,0);
	return 0;
}
