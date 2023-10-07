#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, a[N],f[N];
int len = 1;
int main(){
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	memset(f,0x3f,sizeof f);
	f[0] = 0;
	len = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] > f[len]) f[++len] = a[i];
		else{
			f[lower_bound(f,f+len+1,a[i]) - f] = a[i];
		}
	}
	cout << "max="<< len << endl;
	return 0;
}
