#include <bits/stdc++.h>
#define int long long
const int N = 3e5+10;

using namespace std;
int n,h[N],b[N],top,s[N];
int val[N],f[N],pre[N];

signed main(){
	cin >> n;
	pre[0] = -1e18;
	for(int i = 1; i <= n; i++) cin >> h[i];	
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1;i <= n; i++){
		int tmp = f[i-1];
		while(top && h[i] < h[s[top]]){
			tmp = max(tmp,val[top]);
			top--;
		}
		s[++top] = i;
		val[top] = tmp;
		f[i] = pre[top] = max(pre[top-1],tmp+b[i]);
	}	
	cout << f[n];
	return 0;
}
