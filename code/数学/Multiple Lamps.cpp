#include<bits/stdc++.h> 
#define ll long long
const int N = 5e5+5;
using namespace std;
int T,n,m,a[N],b[N],c[N],d[N],ans[N];
bool ck() {
	for(int i = 1; i <= n; i ++) d[i] = 0,ans[i] = 0;
	for(int i = 1; i <= n; i ++)
		if(d[i] != c[i]) {
			ans[i] = 1;
			for(int j = i; j <= n; j += i) d[j] ^= 1;
		}
	for(int i = 1; i <= m; i ++) if(ans[a[i]] && !ans[b[i]]) return 0;
	return 1;
}
void op() {
	vector<int> acc;
	for(int i = 1; i <= n; i ++) if(ans[i]) acc.push_back(i);
	cout << acc.size() << "\n";
	for(int i : acc) cout << i << " ";
	cout << "\n";
}
void sol() {
	for(int i = 1; i <= n; i ++) c[i] = 0;
	for(int i = 1; i <= n; c[i ++] = 0) {
		c[i] = 1;
		if(ck()) return op();
		if(n / 5 < 2) continue;
		for(int j = i + 1; j <= n; c[j ++] = 0) {
			c[j] = 1;
			if(ck()) return op();
			if(n / 5 < 3) continue;
			for(int k = j + 1; k <= n; c[k ++] = 0)
				if(c[k] = 1,ck()) return op();
		}
	}
	cout << "-1\n";
}
void los() {
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) cin >> a[i] >> b[i];
	if(n >= 20) {
		cout << n << "\n";
		for(int i = 1; i <= n; i ++) cout << i << " ";
		cout << "\n";
		return ;
	}
	if(n <= 4) return cout << "-1\n",void();
	sol();
}
int main() {
	for(cin >> T; T --;) los();
}

