#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
int n, ne[N],f[N],h[N];
string s;

int main(){
	cin >> s;
	n = s.size();
	s = " " + s;
	ne[1] = 0;
	for(int i = 2; i <= n;i++){
		int p = ne[i-1];
		while(p && s[p+1] != s[i]) p = ne[p];
		if(s[p+1] == s[i]) p++;
		ne[i] = p;
	}	
	if(ne[n] == n-1) {
		cout << 1;
		return 0;
	}
	f[1] = 1;
	for(int i = 2; i <=n;i++){
		f[i] = i;
		if(h[f[ne[i]]] >= i - ne[i]) f[i] = f[ne[i]];
		h[f[i]] = i;
	}
	cout << f[n];
	return 0;
}
