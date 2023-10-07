#include<bits/stdc++.h>
using namespace std;
long long n, i, j, s[1005];
int main() {
	cin >> n;
	for (i = n; i >= 0; i--)cin >> s[i];
	for (i = n; i >= 0; i--) {
		if (s[i] == 0)continue;
		if (s[i] > 0 && i != n)cout << '+';
		if (s[i] < 0) {
			cout << "-";
		}
		if (abs(s[i]) != 1 && i != 0)cout << abs(s[i]);
		if (i != 0 && i != 1)cout << "x^" << i;
		if (i == 1)cout << "x";
		if (i == 0)cout << abs(s[i]) << endl;
	}
	return 0;
}
